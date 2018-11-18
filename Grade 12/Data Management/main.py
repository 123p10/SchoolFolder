import csv
#Yellow	10						10
#Cyan	4	3	2		2	3	4
#Blue	6			4			6
#Red	7	3				3	7
#Cost is $3

yellow = [10,0,0,0,0,0,10]
cyan = [4,3,2,0,2,3,4]
blue = [6,0,0,4,0,0,6]
red = [7,3,0,0,0,3,7]

with open('test.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    numRows = 0
    totalCashGivenOut = 0
    wins = 0
    cost = 3
    losses = 0
    for row in csv_reader:
        print(f'{row[0]} {row[1]} {row[2]}')
        numRows += 1
        if row[0] == "Yellow":
            totalCashGivenOut += yellow[int(row[2])-1]
            if yellow[int(row[2])-1] >= cost:
                wins += 1
            else:
                losses += 1
        if row[0] == "Cyan":
            totalCashGivenOut += cyan[int(row[2])-1]
            if cyan[int(row[2])-1] >= cost:
                wins += 1
            else:
                losses += 1
        if row[0] == "Blue":
            totalCashGivenOut += blue[int(row[2])-1]
            if blue[int(row[2])-1] >= cost:
                wins += 1
            else:
                losses += 1
        if row[0] == "Red":
            totalCashGivenOut += red[int(row[2])-1]
            if red[int(row[2])-1] >= cost:
                wins += 1
            else:
                losses += 1
        if row[0] == "Purple":
            losses += 1
    cashGained = numRows * cost
    profit = cashGained - totalCashGivenOut
    ratio = wins/losses

    print("\n")
    print(f"Revenue = {cashGained}")
    print(f"Total Cash Given Out = {totalCashGivenOut}")
    print(f"Profit = {profit}")
    print(f"Player Wins = {wins} \nHouse ties or loses = {losses}")
    print(f"Win/Loss Ratio = {ratio}")
