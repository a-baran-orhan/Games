import ast , sys

def Movement(a, b):  #a = Vertical , b = Horizontal

    vert = position_rabbitList[0] #Vertical
    horiz = position_rabbitList[1] #Horizontal

    Score = 0

    vertCheck = vert + a
    horizCheck = horiz +b

    if vertCheck == -1 or vertCheck == len(res) or horizCheck == -1 or horizCheck == len(res[0]):
        pass

    elif(res[vertCheck][horizCheck] == "P"):
        res[vertCheck][horizCheck] = "*"
        res[vert][horiz] = "X"
        printMap()
        print("Your Score: ", finalScore )
        sys.exit()
        
    elif(res[vertCheck][horizCheck] == "X"):
        res[vertCheck][horizCheck] = "*"
        res[vert][horiz] = "X"
        position_rabbitList[0] += a
        position_rabbitList[1] += b
    elif(res[vertCheck][horizCheck] == "A"):
        res[vertCheck][horizCheck] = "*"
        res[vert][horiz] = "X"
        position_rabbitList[0] += a
        position_rabbitList[1] += b
        Score += 5
        
    elif(res[vertCheck][horizCheck] == "C"):
        res[vertCheck][horizCheck] = "*"
        res[vert][horiz] = "X"
        position_rabbitList[0] += a
        position_rabbitList[1] += b
        Score += 10
        
    elif(res[vertCheck][horizCheck] == "M"):
        res[vertCheck][horizCheck] = "*"
        res[vert][horiz] = "X"
        position_rabbitList[0] += a
        position_rabbitList[1] += b
        Score -= 5
        
    elif res[vertCheck][horizCheck] == "W":
        pass

    return(Score)

def printMap():
    for i in range(0,len(res)): #this for loop prints board
            print(*res[i])
            i += 1

def findPositionRabbit(list, searched):
    for sub_list in list:
        if searched in sub_list:
            return (list.index(sub_list), sub_list.index(searched))



givenMap = input("Please enter feeding map as a list:")
res = ast.literal_eval(givenMap)         #res is list res[0]=['W',.....] LIST

givenDirection = input("Please enter direction of movements as a list:")
list_givenDirection = ast.literal_eval(givenDirection) #['U','U'...]

finalScore = 0


print("Your board is:")
printMap()


position_rabbit = findPositionRabbit(res , "*")
position_rabbitList = list(position_rabbit)
print("Your output should be like this:")

for moves in range(0, len(list_givenDirection)):

    #Up
    if (list_givenDirection[moves] == "U"):
        finalScore += Movement(-1, 0)
            
    #Down
    if (list_givenDirection[moves] == "D"):
        finalScore += Movement(1, 0)

    #Left
    if (list_givenDirection[moves] == "L"):
        finalScore += Movement(0, -1)
        
    #Right
    if (list_givenDirection[moves] == "R"):
        finalScore += Movement(0, 1)
        
printMap()

print("Your Score:", finalScore )
