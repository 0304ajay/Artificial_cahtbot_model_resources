import express, { Request, Response } from 'express';
import axios from 'axios';

const app = express();
const PORT = 3000;
const WINDOW_SIZE = 10;
const TIMEOUT = 500;

interface NumberStore {
  [key: string]: number[];
}

const numberStore: NumberStore = {
  p: [],
  f: [],
  e: [],
  r: []
};

const getApiUrl = (id: string): string => {
  switch (id) {
    case 'p':
      return 'http://20.244.56.144/test/primes'; // Replace with actual URL for primes
    case 'f':
      return 'http://20.244.56.144/test/fibo'; // Replace with actual URL for Fibonacci numbers
    case 'e':
      return 'http://20.244.56.144/test/even'; // Replace with actual URL for even numbers
    case 'r':
      return 'http://20.244.56.144/test/rand'; // Replace with actual URL for random numbers
    default:
      throw new Error('Invalid number ID');
  }
};

const fetchNumber = async (id: string): Promise<number | null> => {
  const url = getApiUrl(id);
  try {
    const response = await axios.get(url, { timeout: TIMEOUT });
    return response.data.number;
  } catch (error) {
    // console.error(`Error fetching number: ${error.message}`);
    return null;
  }
};

const calculateAverage = (numbers: number[]): number => {
  const sum = numbers.reduce((acc, num) => acc + num, 0);
  return sum / numbers.length;
};

app.get('/numbers/:id', async (req: Request, res: Response) => {
  const id = req.params.id;

  if (!['p', 'f', 'e', 'r'].includes(id)) {
    return res.status(400).send('Invalid number ID');
  }

  const number = await fetchNumber(id);
  if (number === null) {
    return res.status(500).send('Error fetching number from third-party server');
  }

  const store = numberStore[id];
  const before = [...store];

  if (!store.includes(number)) {
    if (store.length >= WINDOW_SIZE) {
      store.shift();
    }
    store.push(number);
  }

  const after = [...store];
  const average = store.length > 0 ? calculateAverage(store) : 0;

  res.json({ before, after, average });
});

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
