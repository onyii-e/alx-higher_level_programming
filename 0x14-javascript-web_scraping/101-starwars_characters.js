#!/usr/bin/node

const request = require('request');
const { promisify } = require('util');
const requestPromise = promisify(request);
const id = process.argv[2];
const url = `https://swapi-api.alx-tools.com/api/films/${id}`;

(async () => {
  try {
    const response = await requestPromise(url);
    const content = JSON.parse(response.body);
    const characters = content.characters;

    for (const character of characters) {
      try {
        const charResponse = await requestPromise(character);
        const characterData = JSON.parse(charResponse.body);
        console.log(characterData.name);
      } catch (charError) {
        console.error(charError);
      }
    }
  } catch (error) {
    console.error(error);
  }
})();
