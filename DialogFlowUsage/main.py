import apiai
import json

def send_message(message):
    request = apiai.ApiAI("799d97dc251f4b82a34cf18f0b3e23c4").text_request()
    request.lang = "ru"
    request.session_id = "first_session"
    request.query = message
    response = json.loads(request.getresponse().read().decode("utf-8"))
    print(response['result']['fulfillment']['speech'])
    #print(response)
    return response['result']['action']

message = (input("Напишите что-либо:\n"))
action = None
while True:
    action = send_message(message)
    if action == 'smalltalk.greetings.bye':
        break
    message = input()