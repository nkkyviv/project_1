import json
import os


def gen_include_guard_class_decl_ctor(json_filename):
    top = []  # include guard, class declaration and constructor
    bottom = ""  # ending of include guard
    json_name_upper = json_filename.upper()
    include_guard_name = f'HEADER_{json_name_upper}_H'
    top.append(f'#ifndef {include_guard_name}')
    top.append(f'\n#define {include_guard_name}')
    top.append(f'\n#include <sstream>\n')
    top.append('\n')
    top.append(f'class CAN_{json_filename} {{')
    top.append('\n\tpublic:')
    top.append(f'\n\t\tCAN_{json_filename}();')
    bottom = ['\n};', f'\n#endif //{include_guard_name}']
    return top, bottom


def function_to_generate_header(signal_name, signal_type, signal_length, signal_comment):
    output_data = "\n"
    output_data += '\t\t/*\n\t\tget {}\n\t\t*/' .format(signal_comment)
    output_data += "\n\t\tstd::string get_{}(); \n" .format(signal_name)
    output_data += '\t\t/*\n\t\tset {}\n\t\t*/' .format(signal_comment)
    output_data += "\n\t\tstd::string set_{}({} {}); \n" .format(
        signal_name, signal_type, 'newValue')

    return output_data


def generate_get_set_functions(json_dict):
    content = []
    for signal in json_dict["signals"]:
        signal_name = signal["name"]
        signal_type = signal["type"]
        signal_length = signal["length"]
        signal_comment = signal["comment"]
        get_prototype = function_to_generate_header(
            signal_name, signal_type, signal_length, signal_comment)
        content.append(get_prototype)

    return content


def generate_private_fields(json_dict):
    content = []
    Dtype = "uint8_t"
    content.append(f'\n\t {Dtype} m_startMsgId;')
    for signals in json_dict["signals"]:
        content.append(f'\n\t {signals["type"]} m_{signals["name"]}GetMsgId;')
        content.append(f'\n\t {signals["type"]} m_{signals["name"]}SetMsgId;')

    return content


def generate_header(json_filename, json_dict):
    output = []
    header_top, header_bottom = gen_include_guard_class_decl_ctor(
        json_filename)
    output += header_top
    output += generate_get_set_functions(json_dict)
    output.append('\n\tprivate:')
    output += generate_private_fields(json_dict)
    output += header_bottom  # output = output + header_bottom
    return output


def gen_include_guard_source_class_decl_ctor(json_filename):
    top = []  # include guard, class declaration and constructor
    top.append(f'#include "{HeaderFile}"')
    top.append(f'\n#include <sstream>\n')
    top.append('\n')
    top.append(f'CAN_{Header}::CAN_{Header}() {{\n')
    return top


def generate_source_private_fields(json_dict):
    content = []
    CAN_id = json_dict["id"]

    content.append(f'\t m_startMsgId = {CAN_id};\n')
    for n, signals in zip([1, 2], json_dict["signals"]):
        content.append(
            f'\t m_{signals["name"]}GetMsgId = m_startMsgId + {2*n};\n')
        content.append(
            f'\t m_{signals["name"]}SetMsgId = m_startMsgId + {2*n} + 1 ;\n')
    content.append("}\n")

    return content


def function_to_generate_source(signal_name, signal_type, signal_length):
    output_data = "\n"
    output_data += "std::string CAN_{}::get_{}() {{ \n".format(Header, signal_name)
    output_data += "\tstd::stringstream sstream;\n"
    output_data += '\tsstream << "{{\\"ID\\": " << m_{}GetMsgId\n'.format(
        signal_name)
    output_data += '\t\t\t<< ", \\"length\\":0 "\n'
    output_data += '\t\t\t<< ", \\"value\\": \\"\\"}";\n'
    output_data += "\treturn sstream.str();\n"
    output_data += "}\n"
    output_data += "\nstd::string CAN_{}::set_{}({} newValue) {{\n" .format(
        Header, signal_name, signal_type)
    output_data += "\tstd::stringstream sstream;\n"
    output_data += '\tsstream << "{{\\"ID\\": " << +m_{}SetMsgId\n'.format(
        signal_name)
    output_data += '\t\t\t<< ", \\"length\\":{} "\n'.format(signal_length)
    output_data += '\t\t\t<< ", \\"value\\": \\" "\n'
    output_data += '\t\t\t<< +newValue\n'
    output_data += '\t\t\t<< "\\" }";\n'
    output_data += "\treturn sstream.str();\n"
    output_data += "}\n"

    return output_data


def generate_source_get_set_functions(json_dict):
    content = []
    for signal in json_dict["signals"]:
        signal_name = signal["name"]
        signal_type = signal["type"]
        signal_length = signal["length"]
        get_prototype = function_to_generate_source(
            signal_name, signal_type, signal_length)
        content.append(get_prototype)

    return content


def generate_source(json_filename, json_dict):
    output = []
    source_top = gen_include_guard_source_class_decl_ctor(
        json_filename)
    output += source_top
    output += generate_source_private_fields(json_dict)
    output += generate_source_get_set_functions(json_dict)

    return output


def write_file(filename, data):
    if filename is None or filename == "":
        return
    with open(filename, 'w') as file_fd:
        file_fd.writelines(data)


if __name__ == "__main__":
    input_filename = "min_signals.json"
    HeaderFile = "can_messages/min_signals.h"
    header_file = "output/include/can_messages/min_signals.h"
    source_file = "output/src/min_signals.cpp"
    json_dict = {}
    with open(input_filename) as file_fd:
        json_raw_content = file_fd.read()
        json_dict = json.loads(json_raw_content)
    print(json_dict)

    json_filename = input_filename.replace(".json", "")
    print(json_filename)

    Header = "min_signals"

    header_function = generate_header(json_filename, json_dict)
    write_file(header_file, header_function)
    source_function = generate_source(json_filename, json_dict)
    write_file(source_file, source_function)
