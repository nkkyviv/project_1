import json
  
# Opening JSON file
with open('min_signals.json','r') as file_rd:
    file_read = json.load(file_rd)

    print(file_read)
    print(type(file_read))
  
with open("my_file.txt", "w") as output_file_fd:
    output_file_fd.writelines(file_read)

  
