#!/usr/bin/node
const request = require('request');
const id = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + id;

request(url, { json: true }, (err, res, body) => {
  if (err) { return console.log(err); }
  let names = [];
  let ids = [];
  body.characters.forEach(element => {
    let id = element.split('/')[5];
    ids.push(id);
    request(element, {json: true}, (err, res, body) => {
      if (err) { return console.log(err); }
        if (res.statusCode === 200)
          names[id] = body.name;
      });  
});

setTimeout(function() {
  body.characters.forEach(element => {
    let id = element.split('/')[5];
    console.log(names[id]);
  });
}, 2000);
});
