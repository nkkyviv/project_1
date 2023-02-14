#include "project.h"
#include <can_messages/min_signals.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
using namespace std;

// #define PRINT_DEBUG_LINE_INFO std::cout << __FUNCTION__ << " : " << __LINE__ << std::endl;

std::string parse_get_func_and_call(std::string line)
{
    const std::string set_keyword("get");
    std::string result;
    size_t pos_of_get = line.find(set_keyword);
    size_t pos_start_signal_name = pos_of_get + set_keyword.size() + 1;

    size_t pos_of_separator = line.find(" ", pos_start_signal_name);
    std::string signal_name = line.substr(pos_start_signal_name, pos_of_separator - pos_start_signal_name);

    // windows: \r\n
    // linus: \n
    // bool shall_delete = line[line.size() - 1] == '\r';
    std::string value = line.substr(pos_of_separator + 1);

    std::cout << "signal_name = |" << signal_name << "| value |" << value << "|" << std::endl;

    if (signal_name.compare("temperature") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_temperature();
    }
    else if (signal_name.compare("humidity") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_humidity();
    }
    else if (signal_name.compare("front_sensor_status") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_front_sensor_status();
    }
    else if (signal_name.compare("flow_rate") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_flow_rate();
    }
    else if (signal_name.compare("flow_meter_sensor_status") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_flow_meter_sensor_status();
    }
    else if (signal_name.compare("light_intensity") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_light_intensity();
    }
    else if (signal_name.compare("light_intensity_sensor_status") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_light_intensity_sensor_status();
    }

    else if (signal_name.compare("water_level") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_water_level();
    }
    else if (signal_name.compare("water_level_sensor_status") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_water_level_sensor_status();
    }
    else if (signal_name.compare("soil_moisture") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_soil_moisture();
    }
    else if (signal_name.compare("soil_moisture_sensor_status") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_soil_moisture_sensor_status();
    }
    else if (signal_name.compare("stop_signal_light") == 0)
    {
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.get_stop_signal_light();
    }
    return result;
}

// set volume 100
std::string parse_set_func_and_call(std::string line)
{
    const std::string set_keyword("set");
    std::string result;
    size_t pos_of_set = line.find(set_keyword);
    size_t pos_start_signal_name = pos_of_set + set_keyword.size() + 1;
    // position of set plus the length of the "set" string plus extra whitespace
    size_t pos_of_separator = line.find(" ", pos_start_signal_name);
    std::string signal_name = line.substr(pos_start_signal_name, pos_of_separator - pos_start_signal_name);

    // ignore space we use +1
    // starting from the first symbol after
    // from total length -(position of first element + last element)
    std::string value = line.substr(pos_of_separator + 1);

    std::cout << "signal_name = |" << signal_name << "| value = |" << value << "|" << std::endl;

    if (signal_name.compare("temperature") == 0)
    {
        float f_value = std::stof(value);
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.set_temperature(f_value);
    }
    else if (signal_name.compare("humidity") == 0)
    {
        uint8_t u_value = std::stoul(value) & 0xFF; // to take only the last byte so we use the & bitwise operator
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.set_humidity(u_value);
    }
    else if (signal_name.compare("front_sensor_status") == 0)
    {
        bool b_value = 0;
        CAN_min_signals signal_obj;
        if (value.compare("enabled") == 0)
        {
            b_value = 1;
        }
        return "\t\t" + signal_obj.set_front_sensor_status(b_value);
    }

    else if (signal_name.compare("flow_rate") == 0)
    {
        uint16_t u_value = std::stoul(value) & 0xFF;
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.set_flow_rate(u_value);
    }
    else if (signal_name.compare("flow_meter_sensor_status") == 0)
    {
        uint8_t u_value = std::stoul(value) & 0xFF;
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.set_flow_meter_sensor_status(u_value);
    }

    else if (signal_name.compare("light_intensity") == 0)
    {
        uint8_t u_value = std::stoul(value) & 0xFF;
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.set_light_intensity(u_value);
    }
    else if (signal_name.compare("light_intensity_sensor_status") == 0)
    {
        uint8_t u_value = std::stoul(value) & 0xFF;
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.set_light_intensity_sensor_status(u_value);
    }
    else if (signal_name.compare("water_level") == 0)
    {
        uint8_t u_value = std::stoul(value) & 0xFF;
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.set_water_level(u_value);
    }
    else if (signal_name.compare("water_level_sensor_status") == 0)
    {
        uint8_t u_value = std::stoul(value) & 0xFF;
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.set_water_level_sensor_status(u_value);
    }
    else if (signal_name.compare("soil_moisture") == 0)
    {
        uint8_t u_value = std::stoul(value) & 0xFF;
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.set_soil_moisture(u_value);
    }
    else if (signal_name.compare("soil_moisture_sensor_status") == 0)
    {
        uint8_t u_value = std::stoul(value) & 0xFF;
        CAN_min_signals signal_obj;
        return "\t\t" + signal_obj.set_soil_moisture_sensor_status(u_value);
    }
    else if (signal_name.compare("stop_signal_light") == 0)
    {
        bool b_value = 0;
        CAN_min_signals signal_obj;
        if (value.compare("enabled") == 0)
        {
            b_value = 1;
        }
        return "\t\t" + signal_obj.set_stop_signal_light(b_value);
    }
    return result;
}

/*
convert list of commands into json file using generated class from CAN_messages*/
std::vector<std::string> convert(std::vector<std::string> raw_input)
{
    std::vector<std::string> output;

    for (std::string &line : raw_input)
    {
        size_t pos_of_get = line.find("get");
        if (pos_of_get != std::string::npos && pos_of_get < 2) // npos is returns -1
        {
            // call a function to parse "get" lines.
            std::string out = parse_get_func_and_call(line);
            output.push_back(out);
        }

        size_t pos_of_set = line.find("set");
        if (pos_of_set != std::string::npos && pos_of_set < 2)
        {
            // call a function to parse "set" lines.
            std::string out = parse_set_func_and_call(line);
            output.push_back(out);
        }
    }
    return output;
}

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        std::cerr << "You should call" << std::endl
                  << argv[0] << "input_file output_file" << std::endl;
        return 1;
    }

    std::string input_filename(argv[1]);
    std::string output_filename(argv[2]);

    FileIO input(input_filename);

    std::vector<std::string> input_content = input.read_container();
    for (auto &i : input_content)
    {
        std::cout << i << std::endl;
    }

    std::vector<std::string> output_content = convert(input_content);

    // opening of the json output text file
    std::vector<std::string> final_output = {"{", "\t\"cmds \" : [ "};

    if (output_content.empty() != true)
    {
        auto lineit = output_content.begin();
        for (; std::next(lineit) != output_content.end(); ++lineit)
        {
            final_output.push_back(*lineit + ",");
        }
        final_output.push_back((*lineit));
    }

    // closing the json ouput file
    final_output.emplace_back("\t]");
    final_output.emplace_back("}");

    FileIO output(output_filename);

    for (auto &i : final_output)
    {
        std::cout << i << std::endl;
    }

    output.write_container(final_output);
    input.close();
    output.close();

    return 0;
}