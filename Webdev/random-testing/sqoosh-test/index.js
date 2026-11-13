import { ImagePool } from '@squoosh/api';
const imagePool = new ImagePool();

const imagePath = './images/Screenshot 2025-09-28 at 5.40.48 PM.png';
const image = imagePool.ingestImage(imagePath);

await image.decoded; //Wait until the image is decoded before running preprocessors

const preprocessOptions: {
  resize: {
    enabled: true,
    width: 100,
    height: 50,
  }
}
await image.preprocess(preprocessOptions);

const encodeOptions: {
  mozjpeg: {}, //an empty object means 'use default settings'
}
await image.encode(encodeOptions);

await imagePool.close();

