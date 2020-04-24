from sys import argv
import csv

if len(argv)<3:
    print("Usage: python3 csv_file_name/path text_file_name/path")
    exit(1)

string_file=open(argv[2])

data_string=string_file.read()

def count_dna(string,csvfile):
    bigstringcount=0
    count=0
    dict_dna={}

    for i in csvfile:
        for j in range(1,len(i)):
            if i[j] not in dict_dna:
                dict_dna[i[j]]=0
        break

    for j in dict_dna:
        for i in range(len(string)):
            if(count==0):
                #print(f"comparing {j} to {string[i:i+len(j)]}")
                if string[i:i+len(j)]==j:
                    #print("FOUND!!")
                    dict_dna[j]+=1
                    count=len(j)-1
            else:
                count-=1
    return dict_dna
    

with open(argv[1]) as csv_file:
    dna_data={}
    csv_read=csv.reader(csv_file)

    dna_data=count_dna(data_string,csv_read)

    count=0
    done=0
    for i in csv_read:
        if count==0:
            count+=1
        else:
            #print(f"data is {dna_data['AGATC']} checking with {i[1]}")
            if dna_data["AGATC"]==int(i[1]):
                #print(f"data is {dna_data['AATG']} checking with {i[2]}")
                if dna_data["AATG"]==int(i[2]):
                    #print(f"data is {dna_data['TATC']} checking with {i[3]}")
                    if dna_data["TATC"]==int(i[3]):
                        print(i[0])
                        done=1
    if(done==0):
        print("No match")
    print(dna_data)
        
check="AGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATC"

print(f"len is {len(check)}")