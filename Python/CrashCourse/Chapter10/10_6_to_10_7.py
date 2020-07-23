while True:
    try:
        fir_val = int(input("first val: "))
        sec_val = int(input("sec val: "))
    except ValueError:
        print("Programm expects numbers")
    except EOFError:
        quit()
    else:
        print(fir_val + sec_val)
