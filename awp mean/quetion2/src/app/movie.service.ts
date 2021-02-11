import { Injectable } from '@angular/core';
import { Movie } from './Movie';

@Injectable({
  providedIn: 'root'
})
export class MovieService {


  movies:Movie[];

  constructor() {
    this.movies=[new Movie(1,'Queen','Riya'),new Movie(3,'Dangal','Sanjeev')];

  }
 
  addMovies(movie:Movie){
    this.movies.push(movie);
  }


}
