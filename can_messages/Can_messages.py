import json
  
# Opening JSON file
with open('min_signals.json','r') as file_rd:
    file_read = json.load(file_rd)

    print(file_read)
    print(type(file_read))
  
def write_list(filename, list_to_write):
    if filename is None or filename == " ":
        return
    with open(filename, 'w') as file_wrt:
      file_wrt.writelines(list_to_write)

if __name__ == "__main__":
    write_list("my_file.txt", '%s\n' %file_read)    

    

  
