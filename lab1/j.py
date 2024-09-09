n = []
a = ''
while(a != '!'):
    a = input()
    try:
        if(a[0] == '+'):
            b = int(a[2:])
            n.insert(0, b)
        elif(a[0] == '-'):
            b = int(a[2:])
            n.append(b)
        elif(a[0] == '*'):
            try:
                b = n[0] + n[-1]
                print(b)
                n.pop(0)
                try:
                    n.pop(-1)
                except:
                    pass
            except:
                print("error")
    except:
        pass