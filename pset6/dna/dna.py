from sys import argv
import csv

#check for lack of files
if len(argv)<3:
    print("Usage: python3 csv_file_name/path text_file_name/path")
    exit(1)

#store string input from text files
string_file=open(argv[2])

data_string=string_file.read()

#function to get count of dna strings
def count_dna(string,csvfile):
    bigstringcount=0
    count=0
    dict_dna={}

    #get hold of dna strings to get count from csv file
    for i in csvfile:
        for j in range(1,len(i)):
            #print(i[j])
            if i[j] not in dict_dna:
                dict_dna[i[j]]=0
        break

    #getting biggest string
    for j in dict_dna:
        string_count=0
        string_temp=0
        for i in range(len(string)):
            if(count==0):
                #print(f"comparing {j} to {string[i:i+len(j)]}")
                if string[i:i+len(j)]==j:
                    #print("FOUND!!",string[i:i+len(j)])
                    #dict_dna[j]+=1
                    string_temp+=1
                    count=len(j)-1
                else:
                    if(string_count<string_temp):
                        string_count=string_temp
                        string_temp=0
                    else:
                        string_temp=0

            else:
                count-=1
        dict_dna[j]=string_count
    return dict_dna
    

with open(argv[1]) as csv_file:
    dna_data={}
    csv_read=csv.reader(csv_file)

    dna_data=count_dna(data_string,csv_read)

    count=0
    done=0
    for i in csv_read:
        if count==-1:
            pass
        else:
            #print(f"data is {dna_data['AGATC']} checking with {i[1]}")
            # if dna_data["AGATC"]==int(i[1]):
            #     #print(f"data is {dna_data['AATG']} checking with {i[2]}")
            #     if dna_data["AATG"]==int(i[2]):
            #         #print(f"data is {dna_data['TATC']} checking with {i[3]}")
            #         if dna_data["TATC"]==int(i[3]):
            #             print(i[0])
            #             done=1
            index=1
            for j in dna_data:
               # print(f"dna data[j] is {dna_data[j]} comparing with data of {i[0]} as {i[index]} ")
                if dna_data[j]==int(i[index]):
                    index+=1
                    if index==len(dna_data)+1:
                        #store name
                        Name=i[0]
                        done=1


    if(done==0):
        print("No match")
    else:
        print(Name)
    #print(dna_data)