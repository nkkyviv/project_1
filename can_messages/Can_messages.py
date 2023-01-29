import json
path = 'my_file.txt'
jason = 'min_signals.json' 



#The set function variable
value_type = "newValue"
setType = "uint8_t\t"

m_startMsgId = "m_startMsgId"
m_temperatureGetMsgId = "m_temperatureGetMsgId"
m_temperatureSetMsgId = "m_temperatureSetMsgId"
m_humidityGetMsgId = "m_humidityGetMsgId"
m_humiditySetMsgId = "m_humiditySetMsgId"



json_content = {"id": "0x100"}
json_content["signals"] = [{
            "name": "temperature",
            "type": "float",
            "length": 10,
            "comment": "the ambient temperature"
        },
        {
            "name": "humidity",
            "type": "uint8_t",
            "length": 7,
            "comment": "the ambient humidity percentage"
        }]
json_format = json.dumps(json_content, indent=4)
print("............jason_format............")
print(json_format)

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
    output_data += "\n\tstd::string set_{}({} {}); \n" .format(signal_name, signal_type, value_type)
    return output_data

def create_header_file():
    header_file = "min_signals.h"
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
        myFile.write(function_to_generate_headerFile("CAN_messages", signal_element["name"], signal_element["type"], "newValue", "comment"))


    myFile.write("\nprivate:\n\t" + setType + m_startMsgId + ";" +
        "\n\t" + setType + m_temperatureGetMsgId + ";" +
        "\n\t" + setType + m_temperatureSetMsgId + ";" + 
        "\n\t" + setType + m_humiditySetMsgId + ";" +
        "\n\t" + setType + m_humidityGetMsgId + ";\n")

    myFile.write(destructor)
    myFile.write("};\n" + endif)
    myFile.close()


if __name__ == "__main__":
   read = read_file(jason)  
   print(read) 
   print(type(read))
   write_list(path, '%s\n' %read) 

   output = function_to_generate_headerFile("CAN_min_signals" , "temperature", "float", "newvalue", "the ambient temperature")
   print(output)
   output = function_to_generate_headerFile("CAN_min_signals" , "humidity", "uint8_t", "newvalue", "the ambient humidity percentage")
   print(output)
   
   create_header_file()
  
    

  
