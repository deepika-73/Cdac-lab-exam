import { Component, OnInit } from '@angular/core';
import { NgForm } from '@angular/forms';
import { MovieService } from '../movie.service';

@Component({
  selector: 'app-movie-register',
  templateUrl: './movie-register.component.html',
  styleUrls: ['./movie-register.component.css']
})
export class MovieRegisterComponent implements OnInit {

  constructor(private service:MovieService) { }

  addMovies(movie:NgForm)
  {
    this.service.addMovies(movie.value); 
  }

  ngOnInit(): void {

  }

}
