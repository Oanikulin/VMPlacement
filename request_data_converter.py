from csv import reader
import re

print('Enter file name to convert')
filename = input()

print('Enter output file name')
out_name = input()

out_file = open(out_name, 'w')
job_id = dict()
current_job_id = 0

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
                out_file.write(re.findall("\d+.\d+", datums[2])[0] + ' ')
                out_file.write(re.findall("\d+.\d+", datums[3])[0] + ' ')
                out_file.write(datums[1] + ' ')
                # OS is not given in the Google Cloud traces
                out_file.write('1\n')
            except:
                pass

out_file.close()
