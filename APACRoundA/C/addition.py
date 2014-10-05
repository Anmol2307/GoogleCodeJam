import copy

def findallkeys(dictionary):
    arr1 = []
    arr2 = []
    for key in dictionary:
        arr1.append(key)
            
    for i in arr1:
        value1 = dictionary[i]
        str1, str2 = i.split("+")
        for j in arr1:
            str3, str4 = j.split("+")
            
            # str1 + str3
            if (str2+'+'+str4) in dictionary:
                dictionary[str1+'+'+str3] = dictionary[i] + dictionary[j] - dictionary[str2+'+'+str4]
            elif (str4+'+'+str2) in dictionary:
                dictionary[str1+'+'+str3] = dictionary[i] + dictionary[j] - dictionary[str4+'+'+str2]
                
            # str1 + str4
            if (str2+'+'+str3) in dictionary:
                dictionary[str1+'+'+str4] = dictionary[i] + dictionary[j] - dictionary[str2+'+'+str3]
            elif (str3+'+'+str2) in dictionary:
                dictionary[str1+'+'+str4] = dictionary[i] + dictionary[j] - dictionary[str3+'+'+str2]
            
            #str2 + str3
            if (str1+'+'+str4) in dictionary:
                dictionary[str2+'+'+str3] = dictionary[i] + dictionary[j] - dictionary[str1+'+'+str4]
            elif (str4+'+'+str1) in dictionary:
                dictionary[str2+'+'+str3] = dictionary[i] + dictionary[j] - dictionary[str4+'+'+str1]
            
            #str2 + str4
            if (str1+'+'+str3) in dictionary:
                dictionary[str2+'+'+str4] = dictionary[i] + dictionary[j] - dictionary[str1+'+'+str3]
            elif (str3+'+'+str1) in dictionary:
                dictionary[str2+'+'+str4] = dictionary[i] + dictionary[j] - dictionary[str3+'+'+str1]

            
def main():
    fo = open("C-small-attempt4.in", "r")
    fw = open("output.txt", "w")
    t = int(fo.readline().strip("\n"))
    count = 0
    while t!=0:
        t -= 1
        count += 1
        n = int(fo.readline().strip("\n"))
        dictionary = {}
        while n!=0:
            n -= 1
            expression = fo.readline().strip("\n")
            lis = expression.split("=")
            string = lis[0].split("+")
            st1 = string[0]+ '+' + string[1]
            st2 = string[1]+ '+' + string[0]
            if st1 not in dictionary and st2 not in dictionary: 
                dictionary[lis[0]] = int(lis[1])
        
        
        findallkeys(dictionary)
        
        q = int(fo.readline().strip("\n"))
        fw.write("Case #%d:\n" % count)
        while q!=0:
            q -= 1
            expression = fo.readline().strip("\n")
            str1, str2 = expression.split("+")
            
            if (str1+'+'+str2) in dictionary:
                fw.write(expression+"="+str(dictionary[str1+'+'+str2])+"\n")
            elif (str2+'+'+str1) in dictionary:
                fw.write(expression+"="+str(dictionary[str2+'+'+str1])+"\n")
            
if __name__=="__main__": main()    

    
