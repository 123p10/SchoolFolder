import csv
#Yellow	10						10
#Cyan	4	3	2		2	3	4
#Blue	6			4			6
#Red	7	3				3	7
#Cost is $2

pepperoni = [10,0,0,0,0,0,10]
cheese = [4,3,2,0,2,3,4]
veggie = [6,0,0,4,0,0,6]
canadian = [7,3,0,0,0,3,7]

with open('commaReal.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    numRows = 0
    totalCashGivenOut = 0
    wins = 0
    cost = 2
    anchovies = 0
    losses = 0
    for row in csv_reader:
        print(f'{row[0]} {row[1]} {row[2]}')
        numRows += 1
        if row[0] == "Pepperoni":
            totalCashGivenOut += pepperoni[int(row[2])-1]
            if pepperoni[int(row[2])-1] > cost:
                wins += 1
            else:
                losses += 1
        elif row[0] == "Cheese":
            totalCashGivenOut += cheese[int(row[2])-1]
            if cheese[int(row[2])-1] > cost:
                wins += 1
            else:
                losses += 1
        elif row[0] == "Canadian":
            totalCashGivenOut += canadian[int(row[2])-1]
            if canadian[int(row[2])-1] > cost:
                wins += 1
            else:
                losses += 1
        elif row[0] == "Veggie":
            totalCashGivenOut += veggie[int(row[2])-1]
            if veggie[int(row[2])-1] > cost:
                wins += 1
            else:
                losses += 1
        elif row[0] == "Anchovie":
            losses += 1
            anchovies += 1
    cashGained = numRows * cost
    profit = cashGained - totalCashGivenOut
    ratio = wins/numRows
    anchoviesRate = anchovies / numRows
    print("\n")
    print(f"Revenue = {cashGained}")
    print(f"Total Cash Given Out = {totalCashGivenOut}")
    print(f"Profit = {profit}")
    print(f"Player Wins = {wins} \nHouse ties or loses = {losses}")
    print(f"Win/Loss Ratio = {ratio}")
    print(f"Wins = {wins} \nLosses = {losses}")
