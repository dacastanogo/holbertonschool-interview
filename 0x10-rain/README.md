# 0x10. Rain

## Requirements

- All files are created and executed on Ubuntu 14.04 LTS using Python3 (version 3.4.3)
- All Python code use the PEP 8 style (version 1.7.\*)

## Tasks

### [0. Rain](./0-rain.py)

Given a list of non-negative integers representing walls of width 1, calculate how much water will be retained after it rains.

- Prototype: def `rain(walls)`
- walls is a list of non-negative integers.
- Return: Integer indicating total amount of rainwater retained.
- Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
- If the list is empty return 0.

```
jesse@ubuntu:~/0x10$ cat 0_main.py
```

```python
#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
```

```
jesse@ubuntu:~/0x10$ ./0_main.py
6
```

## Author

- **Pierre Beaujuge** - [PierreBeaujuge](https://www.github.com/PierreBeaujuge)