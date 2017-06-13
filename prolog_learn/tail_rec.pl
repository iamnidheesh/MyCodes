
	%removeitemslessthan6
/*sift([],[]).
sift([X|T],[X|Result]) :- X>6,    %code to add element in the list if x > 6
    sift(T,Result).
sift([Throw|Tail],Result):-       %if above clause fails , traverse rest of the list
    sift(Tail,Result). */
		
		%appendtwolists
/*append([],List,List).
  append([H|T],List2,[H|Result]):-     %code to add element in the list
  	append(T,List2,Result).*/    
		
		%search
/*on(Item,[Item|Rest]).  
on(Item,[DisregardHead|Tail]):-  
	on(Item,Tail).*/


		%deletealloccurenceofapartcularelement
/*delMember(_, [], []).
delMember(X, [X|Xs], Y) :-	  %code to skip element i.e. do'nt add
    delMember(X, Xs, Y).
delMember(X, [T|Xs], [T|Y]) :-    %code to add element in the list
    delMember(X, Xs, Y).*/       

		%replacealloccurenceofapartcularelementwithotherelement
/*replace_all(_, _,[], []).
replace_all(X,R, [X|Xs], [R|Y]) :-	  %code to skip element i.e. do'nt add
    replace_all(X, R,Xs, Y).
replace_all(X, R,[T|Xs], [T|Y]) :-    %code to add element in the list
    replace_all(X, R,Xs, Y).*/
