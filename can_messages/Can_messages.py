import json
path = 'my_file.txt'
jason = 'min_signals.json'


# The set function variable
value_type = "newValue"
setType = "uint8_t\t"

m_startMsgId = "m_startMsgId"
m_temperatureGetMsgId = "m_temperatureGetMsgId"
m_temperatureSetMsgId = "m_temperatureSetMsgId"
m_humidityGetMsgId = "m_humidityGetMsgId"
m_humiditySetMsgId = "m_humiditySetMsgId"
signals_id = "0x100"


# Opening JSON file
def read_file(filename):
    buffer = []
    if filename is None or filename == " ":
        return buffer
    with open(filename, 'r') as file_rd:
        buffer = json.load(file_rd)
        return buffer


with open(jason) as file_rd:
    jason_dict = json.load(file_rd)
    dict_jason = jason_dict


def write_list(filename, list_to_write):
    if filename is None or filename == " ":
        return
    with open(filename, 'w') as file_wrt:
        file_wrt.writelines(list_to_write)


def function_to_generate_headerFile(class_name, signal_name, signal_type, value_type, signal_comment):
    output_data = ""
    output_data += '\t/*\n\tget {}\n\t*/' .format(signal_comment)
    output_data += "\n\tstd::string get_{}(); \n" .format(signal_name)
    output_data += '\t/*\n\tset {}\n\t*/' .format(signal_comment)
    output_data += "\n\tstd::string set_{}({} {}); \n" .format(
        signal_name, signal_type, value_type)
    return output_data


def create_header_file():
    header_file = "output/include/can_messages/min_signals.h"
    myFile = open(header_file, "w")

    ifndef_def = "#ifndef HEADER_MIN_SIGNALS_H"
    define = "#define HEADER_MIN_SIGNALS_H"
    endif = "#endif /*HEADER_MIN_SIGNALS_H */\n"
    include = "#include<sstream>"

    myFile.write("{}\n{}\n\n".format(ifndef_def, define))
    myFile.write("{}\n\n" .format(include))

    class_can = 'class CAN_min_signals\n{'
    public = '\npublic:\n'
    private = '\nprivate:\n'
    constructor = '\tCAN_min_signals();\n'
    destructor = '\t ~CAN_min_signals();\n'

    myFile.write(class_can + public)
    myFile.write(constructor)
    for signal_element in jason_dict["signals"]:
        print(signal_element["name"])
        formatted_string = f'{signal_element["type"]} and {signal_element["length"]}'
        print(formatted_string)
        print(signal_element["comment"])
        myFile.write(function_to_generate_headerFile(
            "CAN_messages", signal_element["name"], signal_element["type"], "newValue", signal_element["comment"]))

    myFile.write("\nprivate:\n\t" + setType + m_startMsgId + ";" +
                 "\n\t" + setType + m_temperatureGetMsgId + ";" +
                 "\n\t" + setType + m_temperatureSetMsgId + ";" +
                 "\n\t" + setType + m_humiditySetMsgId + ";" +
                 "\n\t" + setType + m_humidityGetMsgId + ";\n")

    myFile.write(destructor)
    myFile.write("};\n" + endif)
    myFile.close()


def function_to_generate_sourcefile(class_name, signal_id, signal_name, signal_length, signal_type):
    class_name = "CAN_min_signals"
    output_string = ""
    output_string += "std::string {} :: get_{}() {{\n".format((class_name),
                                                              signal_name)
    output_string += "\tstd::stringstream sstream; \n"
    output_string += '\tsstream << "{{\\"ID\\": "<< m_{}GetMsgId\n'.format(
        signal_name)
    output_string += '\t\t<< ", \\"length\\":0 " \n'.format(signal_length)
    output_string += '\t\t<< ", \\"value\\": \\"\\"; }" \n'
    output_string += "\treturn sstream.str(); \n"
    output_string += "} \n"
    output_string += "std::string {} :: set_{}({} {}) {{\n".format(class_name,
                                                                   signal_name, signal_length, value_type)
    output_string += "\tstd::stringstream sstream; \n"
    output_string += '\tsstream << "{{\\"ID\\": "<< m_{}SetMsgId\n'.format(
        signal_name)
    output_string += '\t\t<< ", \\"length\\":0 " \n'.format(signal_length)
    output_string += '\t\t<< ", \\"value\\": \\"\\"; }" \n'
    output_string += '\t\t<< {}\n'.format(value_type)
    output_string += "\treturn sstream.str(); \n"
    output_string += "} \n"
    return output_string


def create_source_file():
    source_file = "output/src/min_signals.cpp"
    myFiles = open(source_file, "w")

    include = '#include "min_signals.h"'
    string = "#include <sstream>"
    myFiles.write("{}\n\n" .format(include))
    myFiles.write("{}\n\n" .format(string))

    class_Can = 'CAN_min_signals :: CAN_min_signals(){\n'
    myFiles.write(class_Can)

    myFiles.write("\n\t" + m_startMsgId + "=" + signals_id + ";"

                  "\n\t" + m_temperatureGetMsgId + "=" + m_startMsgId + " + 2;"
                  "\n\t" + m_temperatureSetMsgId + "=" + m_startMsgId + " + 2" + " + 1:"
                  "\n\t" + m_humidityGetMsgId + "=" + m_startMsgId + " + 4;"
                  "\n\t" + m_humiditySetMsgId + "=" + m_startMsgId + " + 4" + " + 1;\n"
                  "}\n")

    for signal_element in jason_dict["signals"]:
        print(signal_element["name"])
        formatted_string = f'{signal_element["type"]} and {signal_element["length"]}'
        print(formatted_string)
        myFiles.write(function_to_generate_sourcefile("CAN_messages", "ID",
                                                      signal_element["name"], signal_element["type"], signal_element["length"]))

    myFiles.close()


if __name__ == "__main__":
    read = read_file(jason)
    print(read)
    print(type(read))
    write_list(path, '%s\n' % read)

    output = function_to_generate_headerFile(
        "CAN_min_signals", "temperature", "float", "newvalue", "the ambient temperature")
    print(output)
    output = function_to_generate_headerFile(
        "CAN_min_signals", "humidity", "uint8_t", "newvalue", "the ambient humidity percentage")
    print(output)

    create_header_file()
    create_source_file()
