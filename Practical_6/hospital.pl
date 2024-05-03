symptom('Flu').
symptom('Yellowish eyes and skin').
symptom('Dark color urine').
symptom('Pale bowel movement').
symptom('Fatigue').
symptom('Vomitting').
symptom('Fever').
symptom('Pain in joints').
symptom('Weakness').
symptom('Stomach Pain').
symptom('Red eyes').
symptom('Rashes').
symptom('Itching in skin').
symptom('Sneezing').
symptom('Swollen eyes').
symptom('Wheezing').
symptom('Runny nose').
symptom('Stuffy nose').

treatment('Flu', 'Drink hot water, avoid cold eatables.').
treatment('Yellowish eyes and skin', 'Put eye drops, have healthy sleep, do not strain your eyes.').
treatment('Dark color urine', 'Drink lots of water, juices and eat fruits. Avoid alcohol consumption.').
treatment('Pale bowel movement', 'Drink lots of water and exercise regularly.').
treatment('Fatigue', 'Drink lots of water, juices and eat fruits.').
treatment('Vomitting', 'Drink salt and water.').
treatment('Fever', 'Put hot water cloth on head and take crocin.').
treatment('Pain in Joints', 'Apply pain killer and take crocin.').
treatment('Weakness', 'Drink salt and water, eat fruits.').
treatment('Stomach Pain', 'Avoid outside food and eat fruits.').
treatment('Red eyes', 'Put eye drops, have healthy sleep, do not strain your eyes.').
treatment('Rashes', 'Clean your skin and keep drinking water.').
treatment('Itching in skin', 'Put eye drops, have healthy sleep, do not strain your eyes.').
treatment('Sneezing', 'Keep away from dusty environment. Dont dring cold water').
treatment('Swollen eyes', 'Put eye drops.').
treatment('Wheezing', 'Drink warm water. Do gargles with salt water.').
treatment('Runny nose', 'Keep away from dusty environment. Dont dring cold water').
treatment('Stuffy nose', 'Use inhaler. Take steam therapy').

input :- dynamic(patient/2),
    repeat,
    symptom(X),
    write('Does the patient have '),
    write(X),
    write('? '),
    read(Y),
    assert(patient(X,Y)),
    \+ not(X='Stuffy nose'),
    not(output).

disease(hemochromatosis) :- 
    patient('Stomach Pain',yes),
    patient('Pain in joints',yes),
    patient('Weakness',yes),
    patient('Dark color urine',yes),
    patient('Yellowish eyes and skin',yes).

disease(hepatitis_c) :-
    not(disease(hemochromatosis)),
    patient('Pain in joints',yes),
    patient('Fever',yes),
    patient('Fatigue',yes),
    patient('Vomitting',yes),
    patient('Pale bowel movement',yes).

disease(hepatitis_b) :-
    not(disease(hemochromatosis)),
    not(disease(hepatitis_c)),
    patient('Pale bowel movement',yes),
    patient('Dark color urine',yes),
    patient('Yellowish eyes and skin',yes).

disease(hepatitis_a) :-
    not(disease(hemochromatosis)),
    not(disease(hepatitis_c)),
    not(disease(hepatitis_b)),
    patient('Flu',yes),
    patient('Yellowish eyes and skin',yes).

disease(jaundice) :-
    not(disease(hemochromatosis)),
    not(disease(hepatitis_c)),
    not(disease(hepatitis_b)),
    not(disease(hepatitis_a)),
    patient('Yellowish eyes and skin',yes).

disease(flu) :-
    not(disease(hemochromatosis)),
    not(disease(hepatitis_c)),
    not(disease(hepatitis_b)),
    not(disease(hepatitis_a)),  
    patient('Flu',yes).

disease(allergy) :-
    not(disease(hemochromatosis)),
    not(disease(hepatitis_c)),
    not(disease(hepatitis_b)),
    not(disease(hepatitis_a)),
    patient('Red eyes', yes),
    patient('Rashes', yes),
    patient('Itching in skin', yes).

disease(cold) :-
    patient('Sneezing', yes),
    patient('Weezing', yes),
    patient('Runny nose', yes),
    patient('Stuffy nose', yes).


output:-
    nl,
    possible_diseases,
    nl,
    advice.

possible_diseases :- disease(X), write('The patient may suffer from '), write(X),nl.
advice :- symptom(X), patient(X,yes), treatment(X,Y), write(Y),nl, \+ not(X='Stomach Pain').

:-input.