with open("test1.txt", "r") as f:
    content = f.read()
    lines = content.split('\n')
    for line in lines:
        print(line)