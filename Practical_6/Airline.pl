% Facts
flight(sfo, jfk, 8:00, 11:00, aa101, 200, 150).
flight(sfo, jfk, 12:00, 15:00, dl321, 180, 120).
flight(jfk, sfo, 9:00, 12:00, aa102, 220, 160).
flight(jfk, sfo, 16:00, 19:00, dl322, 190, 130).

cargo(fruit, 20, 100).
cargo(vegetables, 30, 150).
cargo(electronics, 10, 200).
cargo(clothing, 15, 120).

% Rules
can_transport(Cargo, Origin, Destination, DepartureTime, ArrivalTime, FlightNumber) :-
    flight(Origin, Destination, DepartureTime, ArrivalTime, FlightNumber, Capacity, _),
    cargo(Cargo, Weight, _),
    Weight =< Capacity.

% Queries
% Check if fruit can be transported from SFO to JFK.
?- can_transport(fruit, sfo, jfk, _, _, _).

% Check if electronics can be transported from JFK to SFO.
% ?- can_transport(electronics, jfk, sfo, _, _, _).
