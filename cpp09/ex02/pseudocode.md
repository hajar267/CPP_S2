2 5 9 8 3 0 4 7 10 53
main : 5 9 3 7 53
pend : 2 8 0 4 10

reccursion ->
main : 9 7
pend : 5 3
odd : 53

reccursion ->
main : 9
pend : 7
   we have just one number so the reccursion breaks

insert 7 in the main it will 7 9 (so we use just 0 from jacobs)
insert 5 and 3 into [7,9] (using just 1 from sequence of jacobs)
insert 2,8,0,4,10 into [3,5,7,9] (unsing just 3 from jacobs )

the problem i can't get where is the optimization using jacobs order over just a norml binary searsh why the order matters