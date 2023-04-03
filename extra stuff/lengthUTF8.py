

def bytesToCodePoints(byteArr):
    length = 0
    index = 0
    
    while index < len(byteArr):
        byte = byteArr[index]
        charLength = 1
        if byte & 128 == 0:
            pass # most signiifcant bit is 0
        elif byte & 32 == 0:
            charLength = 2 # 3rd bit is 0
        elif byte & 16 == 0:
            charLength = 3 # 4th bit is 0
        else:
            charLength = 4 # 5th bit is 0

        length +=1
        index += charLength

    return length


# emojis = "😂😃🧘🏻‍♂️🌍🌦️🥖🚗📱🎉❤️✅"
# emoji = "🧘🏻‍♂️"
# string = 'Gödelカカ'
# print(len(emojis))
# print(len(emoji))
# print(len(string))
# print(bytesToCodePoints(bytes(emojis,'utf-8')))
# print(bytesToCodePoints(bytes(emoji,'utf-8')))
# print(bytesToCodePoints(bytes(string,'utf-8')))
