import json
  
# Opening JSON file
with open('min_signals.json', r) as file_rd:
    file_read = json.load(file_rd)

    print(file_read)
    print(type(file_rd))
  

  
