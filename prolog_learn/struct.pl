course(
	cse110,
	day(mon,wed),
	time(11,12),
	prof(holton,bryce),
	coor105
	 ).

course(

	cse340,
	day(mon,wed),
	time(11,12),
	prof(nidheesh,pandey),
	coor321
	).

instructor(Instructor,Class) :-
	
	course(		Class,
			_,
			_,
			Instructor,
			_
		).
