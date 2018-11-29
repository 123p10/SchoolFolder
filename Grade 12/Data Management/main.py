import csv
import matplotlib.pyplot as plt
import numpy as np
#Yellow	10						10
#Cyan	4	3	2		2	3	4
#Blue	6			4			6
#Red	7	3				3	7
#Cost is $2

pepperoni = [10,0,0,0,0,0,10]
cheese = [4,3,2,0,2,3,4]
veggie = [6,0,0,4,0,0,6]
canadian = [7,3,0,0,0,3,7]

p = []
ch = []
v = []
ca = []
runningPayout = []
profitOverTime = []
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
            p.append(int(row[2])-1)
            totalCashGivenOut += pepperoni[int(row[2])-1]
            runningPayout.append(pepperoni[int(row[2])-1])

            if pepperoni[int(row[2])-1] > cost:
                wins += 1
            else:
                losses += 1
        elif row[0] == "Cheese":
            ch.append(int(row[2])-1)
            totalCashGivenOut += cheese[int(row[2])-1]
            runningPayout.append(cheese[int(row[2])-1])

            if cheese[int(row[2])-1] > cost:
                wins += 1
            else:
                losses += 1
        elif row[0] == "Canadian":
            ca.append(int(row[2])-1)
            totalCashGivenOut += canadian[int(row[2])-1]
            runningPayout.append(canadian[int(row[2])-1])

            if canadian[int(row[2])-1] > cost:
                wins += 1
            else:
                losses += 1
        elif row[0] == "Veggie":
            v.append(int(row[2])-1)
            totalCashGivenOut += veggie[int(row[2])-1]
            runningPayout.append(veggie[int(row[2])-1])

            if veggie[int(row[2])-1] > cost:
                wins += 1
            else:
                losses += 1
        elif row[0] == "Anchovie":
            losses += 1
            anchovies += 1
            runningPayout.append(0)
        profitOverTime.append(cost*numRows - totalCashGivenOut)
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


    typeOfGraph = 3
    if typeOfGraph == 0:
        plt.title('Cash Prizes Given Out')
        plt.ylabel("Winnings")
        plt.xlabel("Trial No.")
        heights = runningPayout
        bars = tuple(range(1,119))
        y_pos = np.arange(len(bars))
        plt.bar(y_pos, heights)
        plt.show()
        plt.show()
    elif typeOfGraph == 1:
        m,b = np.polyfit(range(1,119),profitOverTime,1)
        plt.title('Tracking the Profit over Time')
        plt.xlabel("No. of Trials")
        plt.ylabel("Profit")
        plt.plot([1,118],[m+b,118*m+b])
        plt.plot(profitOverTime)
        plt.show()
    elif typeOfGraph == 2:
        plt.title("Spinner Values")
        plt.ylabel("Number of Spins")
        heights = [len(p),len(ch),len(ca),len(v),anchovies]
        bars = ('Pepperoni','Cheese','Canadian','Veggie','Anchovies')
        y_pos = np.arange(len(bars))
        plt.bar(y_pos, heights)
        plt.xticks(y_pos, bars)
        plt.show()
    elif typeOfGraph == 3:
        labels = 'Pepperoni','Cheese','Canadian','Veggie','Anchovies'
        sizes = [len(p),len(ch),len(ca),len(v),anchovies]
        plt.pie(sizes,labels=labels,autopct='%1.1f%%',shadow=True)
        plt.show()
