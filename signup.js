    const {MongoClient} = require('mongodb');
    const url = 'mongodb://localhost:27017';
    const client = new MongoClient(url);

    async function getData() {
        let result = await client.connect();
        result
    }

    getData();