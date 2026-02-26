# tpmp-lab2-task3

## Overview
Program for managing goods data using C structures. Implements TOVAR structure with fields:
- Goods name
- Quantity
- Price
- Receipt date (year, month, day)

## Author
Kudinova Elizaveta, group 12

## Usage
1. Build the program:
```bash
make
```

1. Run the program:

```bash
make run
```

or directly:

```bash
./bin/task3_program
```

1. Clean build files:

```bash
make clean
```

## Functions implemented

- **add_tovar** - add new goods (max 10 items)
- **calculate_average_price** - calculate average price of all goods
- **sort_by_price** - sort goods by price (ascending)
- **print_old_goods** - show goods received more than 10 months ago
- **print_all_goods** - display all goods

## Additional Notes

- Maximum 10 goods can be stored
- No global variables used (all data passed as parameters)
- Date comparison uses current system date
- GitHub Actions configured for automatic build verification
