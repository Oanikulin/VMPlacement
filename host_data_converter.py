from csv import reader
import re

print('Enter file name to convert')
filename = input()

print('Enter output file name')
out_name = input()

out_file = open(out_name, 'w')

with open(filename, 'r') as fd:
    csv_reader = reader(fd)
    count = 0
    for row in csv_reader:
        count += 1
        if count > 3:
            try:
                datums = []
                for elem in row:
                    datums.extend(elem.split('|'))
                out_file.write(re.findall("\d+.\d+", datums[5])[0] + ' ')
                out_file.write(re.findall("\d+.\d+", datums[6])[0] + ' ')
                out_file.write(str(float(re.findall("\d+.\d+", datums[5])[0]) / 2) + ' ')
                out_file.write(re.findall("\d+.\d+", datums[5])[0] + '\n')
            except:
                pass

out_file.close()
