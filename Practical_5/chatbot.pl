% Define some basic facts about the chatbot.
response(greeting, "Hello! How can I assist you today?").
response(goodbye, "Goodbye! Have a great day!").
response(thanks, "You're welcome!").

% Define rules for responding to different types of input.

respond(Input, Response) :-
    greeting(Input), !,
    response(greeting, Response).
    
respond(Input, Response) :-
    goodbye(Input), !,
    response(goodbye, Response).
    
respond(Input, Response) :-
    thanks(Input), !,
    response(thanks, Response).

% Define predicates to recognize specific types of input.

greeting(Input) :-
    member(Input, ["hello", "hi", "hey"]).

goodbye(Input) :-
    member(Input, ["goodbye", "bye", "see you"]).

thanks(Input) :-
    member(Input, ["thanks", "thank you"]).

% Main predicate to interact with the chatbot.

chat :-
    write("You: "),
    read_line_to_string(user_input, Input),
    respond(Input, Response),
    format("Chatbot: ~s~n", [Response]),
    chat.

% Start the chat.
:- initialization(chat).
