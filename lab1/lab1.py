import os
import re

if __name__ == "__main__":
    print('pattern: ')
    pattern = input()
    if len(pattern) == 0:
        pattern = '.*.txt'
    if pattern[0] != '.':
        pattern = '.' + pattern + '*'
        
    print('result file:')
    res_file = input()
    if len(res_file) == 0:
        res_file = '/home/mora/University/docs/osis/file.txt'

    found_files = []
    for root, dirs, files in os.walk('/home/mora/University/docs/osis/'):
        for f in files:
            if re.search(pattern, f):
                found_files.append(f)
                
    print(found_files)
        
    with open(res_file, 'a') as f:
        f.write('search files {}\n'.format(pattern))
        for i in found_files:
            f.write(i + '\n')