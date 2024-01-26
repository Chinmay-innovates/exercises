import json
with open ('hello.json','r') as file:
    data=json.load(file)

print(data)