s1 = "Q}|u`sfg~sf{}|a3"
s2 = "Congratulations!"
print("s1 is :", (s1));
print("s2 is :", (s2));
print("XOR value between S1 and S2 is :\n")
result = [ord(a) ^ ord(b) for a,b in zip(s1,s2)]
print(result);
