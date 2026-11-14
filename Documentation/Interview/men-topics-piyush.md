# MERN Stack & Backend System Curriculum (Piyush Garg)

> **Source Playlist:** [Node.js Tutorial Series by Piyush Garg](https://www.youtube.com/playlist?list=PLinedj3B30sDby4Al-i13hQJGQoRQDfPo)  
> **Scope:** Complete, video-by-video curriculum strictly focused on **MERN Stack, Backend Architecture, and DevOps**.  
> *(Non-MERN videos such as EJS templating, Discord bots, Serverless/Lambda, and the GraphQL/PostgreSQL series are excluded from the main track and documented at the end).*

---

## Video 01: What is NodeJS?
- **Core Definition:** Node.js is an open-source, cross-platform JavaScript Runtime Environment built on Google Chrome's open-source V8 JavaScript Engine.
- **What Node.js is NOT:** It is neither a programming language (the language is JavaScript), nor a framework, nor a library.
- **The Browser Sandbox Limitation:** Historically, JavaScript only executed inside browsers (Chrome, Firefox, Safari) within a locked sandbox that prevented access to the operating system, file system, and machine resources.
- **Different Browser Engines:** Chrome uses **V8**; Firefox uses **SpiderMonkey**; Safari uses **JavaScriptCore (Nitro)**.
- **Ryan Dahl's Innovation (2009):** Extracted the C++ V8 engine from Chrome, wrapped/embedded it in C++, and added low-level C++ bindings to give JavaScript the ability to run directly on the host operating system.
- **Unlocked Capabilities:** By wrapping V8 in C++, JavaScript gained file system handling, access to system hardware, network sockets, and the ability to listen on TCP/HTTP ports to build standalone web servers.

---

## Video 02: Node JS Installation
- **Official Source:** Downloading installers and packages from `nodejs.org`.
- **LTS vs. Current Releases:**
  - **LTS (Long Term Support):** Recommended for all production backends; guarantees long-term stability, bug fixes, and critical security patches.
  - **Current:** Contains experimental, cutting-edge features; subject to breaking changes.
- **Odd-Even Versioning System:**
  - Even-numbered major releases (e.g., Node 16, 18, 20) become stable LTS releases.
  - Odd-numbered major releases (e.g., Node 17, 19, 21) are short-lived Current/experimental releases.
- **CLI Verification:** Verifying installation via terminal:
  - `node -v` (checks Node.js runtime version).
  - `npm -v` (checks Node Package Manager version).
- **The Node.js REPL (Read-Eval-Print Loop):**
  - Launching the interactive terminal environment (`node`).
  - Executing JS expressions line-by-line in the CLI for debugging, prototyping, and testing.

---

## Video 03: Hello World NodeJS
- **Script Execution:** Creating a JavaScript file (`hello.js` / `index.js`) and running it via the command line: `node hello.js`.
- **Browser vs. Node Environment Difference (DOM Removal):**
  - Demonstrating that browser-specific objects and UI methods (e.g., `window`, `document`, `alert()`) throw `ReferenceError: alert is not defined` in Node.js.
  - Node.js stripped away all DOM and window APIs from V8 because a backend server has no graphical window or screen to render UI.
- **Project Initialization with npm (`npm init`):**
  - Running `npm init` (or `npm init -y`) to scaffold a Node.js project.
  - Understanding `package.json` fields: `name`, `version`, `description`, `main` (entry point file), `keywords`, `author`, `license`.
- **Custom npm Scripts:**
  - Defining executable shortcuts inside the `"scripts"` object in `package.json` (e.g., `"start": "node hello.js"`).
  - Running predefined scripts with `npm start` and arbitrary custom scripts with `npm run <script-name>`.

---

## Video 04: Modules in NodeJS
- **Modular Programming:** Decomposing monolithic codebases into isolated, reusable, and maintainable files.
- **CommonJS (CJS) Module System:** The standard default module format in Node.js.
- **Exporting Modules:**
  - Single export: `module.exports = addFunction;`
  - Multi-export via object: `module.exports = { add, sub };`
  - Direct property export: `exports.add = (a, b) => a + b;`
  - Overwriting caveat: Calling `module.exports = add` and subsequently `module.exports = sub` overwrites the first export; multi-exports require an object wrapper.
- **Importing Modules (`require`):**
  - Relative file paths: `require('./math')` (looks in current project directory; `./` is mandatory for local files).
  - Built-in / package resolution: `require('crypto')` or `require('express')` (Node looks in native built-in modules first, then in `node_modules`).
  - Destructuring imports: `const { add, sub } = require('./math');`
- **ES Modules (ESM) Comparison:** Briefly comparing CommonJS `require`/`module.exports` with ES6 `import`/`export` syntax (enabled via `"type": "module"` in `package.json`).

---

## Video 05: File Handling in NodeJS
- **Native `fs` (File System) Module:** Built-in module for disk I/O operations (`const fs = require('fs')`).
- **Synchronous (Blocking) vs. Asynchronous (Non-Blocking) I/O:**
  - **Writing Files:**
    - Sync: `fs.writeFileSync('./test.txt', 'Hello World');` (blocks execution thread until written).
    - Async: `fs.writeFile('./test.txt', 'Hello World', (err) => {});` (offloads work, requires error-first callback).
  - **Reading Files:**
    - Sync: `const result = fs.readFileSync('./contacts.txt', 'utf-8');` (returns content directly, requires encoding string).
    - Async: `fs.readFile('./contacts.txt', 'utf-8', (err, result) => {});` (does not return directly; passes result to callback).
- **Appending Data:**
  - `fs.appendFileSync('./log.txt', `${Date.now()}: User Logged In\n`);` (appends content without overwriting).
- **Managing Files & Directories:**
  - Copying files: `fs.cpSync('./test.txt', './copy.txt');`
  - Deleting files: `fs.unlinkSync('./copy.txt');`
  - File metadata: `const stats = fs.statSync('./test.txt');` (inspecting `stats.isFile()`, `stats.size`, creation date).
  - Creating directories: `fs.mkdirSync('my-docs/a/b', { recursive: true });`
- **Core Production Rule:** Synchronous fs methods block the single JavaScript execution thread; always avoid them in high-concurrency request handlers.

---

## Video 06: How NodeJS Works? (Architecture & Event Loop)
- **Single-Threaded Non-Blocking Architecture:** How Node.js handles high concurrency using a single JavaScript main thread.
- **Request Lifecycle:**
  1. Incoming client requests enter the **Event Queue**.
  2. The **Event Loop** continuously monitors and picks up requests in a First-In, First-Out (**FIFO**) sequence.
  3. **Non-Blocking Operations:** Simple computations, synchronous validations, and immediate operations are processed directly on the main thread and returned to the client immediately.
  4. **Blocking / Heavy I/O Operations:** File system I/O, database queries, cryptography, and network requests are offloaded to the **Libuv Thread Pool**.
- **Libuv & The C++ Thread Pool:**
  - Background worker threads pick up blocking tasks.
  - Upon task completion, workers place the corresponding callback into the **Callback Queue**.
  - The Event Loop pushes the callback onto the call stack once it is empty.
- **Thread Pool Limits:**
  - Default Libuv thread pool size is **4 threads**.
  - Machine CPU core limits inspected via `os.cpus().length` using the native `os` module.

---

## Video 07: Building HTTP Server in NodeJS
- **Native `http` Module:** Creating web servers without external packages (`const http = require('http')`).
- **Server Creation & Lifecycle:**
  - `const server = http.createServer((req, res) => { ... });`
  - Activating the listener: `server.listen(PORT, callback);`
- **Request Object (`req`):** An instance of `http.IncomingMessage` containing headers, HTTP verb (`req.method`), and endpoint path (`req.url`).
- **Response Object (`res`):** An instance of `http.ServerResponse`.
  - Setting headers & status code: `res.writeHead(200, { 'Content-Type': 'text/plain' });`
  - Streaming data chunks: `res.write('Hello');`
  - Finalizing response: `res.end(' World');`
- **Manual Routing:** Using conditional branching (`if (req.url === '/') ... else if (req.url === '/about') ...`) to return different responses for different routes.

---

## Video 08: Handling URLs in NodeJS
- **Anatomy of a Uniform Resource Locator (URL):**
  - Protocol (`http://`, `https://`)
  - Domain / Host (`localhost:8000`, `api.example.com`)
  - Port (`8000`, `443`)
  - Pathname (`/about`, `/contact`)
  - Query Parameters (`?name=piyush&userId=123`)
- **Native `url` Module:**
  - Parsing URL strings: `const myUrl = url.parse(req.url, true);`
  - Passing `true` as the second argument automatically parses query string parameters into a structured JavaScript object (`myUrl.query`).
- **Multi-Route Handling with Query Support:**
  - Extracting `myUrl.pathname` to separate the route from query variables.
  - Using `switch (myUrl.pathname)` to handle multi-route dispatching cleanly.

---

## Video 09: HTTP METHODS
- **RESTful HTTP Verbs & Semantics:**
  - **GET:** Retrieves a resource. Must be safe and idempotent (must never modify server state).
  - **POST:** Submits data to the server to create a new resource. Non-idempotent.
  - **PUT:** Completely replaces an existing resource with the request payload. Idempotent.
  - **PATCH:** Partially updates specified fields of an existing resource.
  - **DELETE:** Removes the specified resource from the server. Idempotent.
- **Idempotency in API Design:** An operation is idempotent if executing it multiple times produces the exact same server state as executing it once ($f(f(x)) = f(x)$).
- **Inspecting HTTP Verbs in Native Node:** Branching logic based on `req.method` inside HTTP handlers.

---

## Video 10: Getting Started with Express and NodeJS
- **Why Express.js?** Native `http` requires tedious manual boilerplate: manual URL parsing, query string parsing, body chunk stream accumulation, and nested `if/else` route branching. Express is a minimalist, fast, unopinionated routing framework built on top of native `http`.
- **Installation:** `npm install express`.
- **Basic Server Initialization:**
  ```javascript
  const express = require('express');
  const app = express();

  app.get('/', (req, res) => res.send('Hello from Home Page'));
  app.get('/about', (req, res) => res.send(`Hello ${req.query.name}`));

  app.listen(8000, () => console.log('Server started on port 8000'));
  ```
- **Express Abstractions:**
  - Automatic URL & query string parsing (accessible directly via `req.query`).
  - Automatic `Content-Type` header setting (`res.send()` sets `text/html` or `application/json` automatically).
  - Dedicated JSON response helper (`res.json()`).

---

## Video 11: How Versioning Works in NodeJS? (SemVer)
- **Semantic Versioning (SemVer) Format:** `MAJOR.MINOR.PATCH` (e.g., `4.18.2`).
  - **MAJOR:** Breaking changes; incompatible API updates.
  - **MINOR:** Backward-compatible new features and additions.
  - **PATCH:** Backward-compatible bug fixes and security patches.
- **Prefix Symbols in `package.json`:**
  - **Caret (`^`):** Automatically upgrades Minor and Patch versions on `npm install`, but locks Major version (e.g., `^4.18.2` allows updating up to `4.19.0`, but prevents `5.0.0`).
  - **Tilde (`~`):** Automatically upgrades Patch versions only (e.g., `~4.18.2` allows `4.18.3`, but prevents `4.19.0`).
  - **Exact Version (No prefix):** Strictly installs the exact version specified (e.g., `4.18.2`).
- **`package.json` vs. `package-lock.json`:**
  - `package.json`: Declares intended semantic version ranges.
  - `package-lock.json`: Locks the exact resolved dependency tree, download URLs, and cryptographic SHA integrity hashes for guaranteed reproducible builds across team environments.

---

## Video 12: What is REST API?
- **REST (Representational State Transfer) Architectural Principles:**
  - **Client-Server Separation:** Complete decoupling of the client user interface from server data storage and business logic.
  - **Statelessness:** Every request must contain all necessary authentication credentials and context; the server does not store client session states between calls.
  - **Uniform Interface:** Standardized endpoint URIs using nouns rather than verbs (e.g., `GET /api/users` instead of `/api/getUsers`).
  - **Layered System:** The client cannot tell whether it communicates directly with the application server or through intermediate proxies, caches, and load balancers.
- **Data Interchange Standard:** JSON (JavaScript Object Notation) as the universal format for modern REST architectures.

---

## Video 13: Building REST API's using Node and Express.js
- **CRUD Resource Design (Mock Data Prototype):**
  - `GET /api/users` – Retrieve list of all users.
  - `GET /api/users/:id` – Retrieve a specific user using path parameters (`req.params.id`).
  - `POST /api/users` – Create a new user record from payload (`req.body`).
  - `PATCH /api/users/:id` – Partially edit a specific user record.
  - `DELETE /api/users/:id` – Delete a specific user record.
- **Route Chaining with `app.route()`:**
  - Grouping different HTTP verbs under the same endpoint URI:
    ```javascript
    app.route('/api/users/:id')
      .get(getUserHandler)
      .patch(updateUserHandler)
      .delete(deleteUserHandler);
    ```

---

## Video 14: Introduction to POSTMAN for REST API's
- **Why Postman is Required:** Web browser address bars can only perform `GET` requests; testing `POST`, `PUT`, `PATCH`, and `DELETE` requests requires a dedicated HTTP client.
- **Configuring Requests:**
  - Selecting HTTP verbs (`GET`, `POST`, `PATCH`, `DELETE`).
  - Setting request headers (`Content-Type: application/json`).
  - Providing JSON payloads inside the **Raw Body** tab.
- **Response Inspection:**
  - Validating response data, HTTP status codes, latency in milliseconds, payload size, and response headers.

---

## Video 15: Express Middleware
- **The Middleware Pattern:** Functions that execute sequentially during the request-response lifecycle before control reaches the final route handler.
- **Middleware Signature:** `(req, res, next) => { ... }`.
- **The `next()` Function:** Passes execution control to the next middleware in line. Failing to call `next()` or send a response hangs the client request indefinitely.
- **Modifying Request & Response Objects:** Attaching metadata to `req` (e.g., `req.myUserName = 'Piyush'`) which remains accessible in subsequent handlers.
- **Built-in & Form-Data Middlewares:**
  - `app.use(express.urlencoded({ extended: false }));` – Parses incoming URL-encoded form submissions into `req.body`.
- **Execution Order:** Middlewares execute strictly in the sequential order in which they are registered with `app.use()`.

---

## Video 16: What are HTTP Headers in API
- **HTTP Headers Overview:** Key-value metadata pairs transmitted in HTTP requests and responses (analogous to the postal envelope carrying delivery details for a letter).
- **Request Headers vs. Response Headers:**
  - Request Headers: Sent by client to convey device, language, and content expectations (`User-Agent`, `Accept`, `Authorization`).
  - Response Headers: Sent by server to inform the client about payload format, caching policies, and server identity (`Content-Type`, `Date`).
- **Inspecting Headers in Express:** Reading incoming request headers via `req.headers`.
- **Setting Custom Response Headers:**
  - Using `res.setHeader('X-MyName', 'Piyush Garg');`.
  - **The `X-` Prefix Convention:** Industry standard practice of prefixing non-standard custom application headers with `X-` (e.g., `X-Total-Count`, `X-App-Version`).
- **Security Headers:** Understanding default headers like `X-Powered-By: Express` and why removing or masking them prevents server technology fingerprinting.

---

## Video 17: HTTP Status Codes & nodemon
- **Standardized Status Code Ranges:**
  - `1xx` – Informational.
  - `2xx` – Success: `200 OK` (Standard success), `201 Created` (Resource successfully created via POST).
  - `3xx` – Redirection: `301 Moved Permanently`, `302 Found`.
  - `4xx` – Client Errors: `400 Bad Request` (Missing fields/syntax), `401 Unauthorized`, `403 Forbidden`, `404 Not Found`.
  - `5xx` – Server Errors: `500 Internal Server Error`.
- **Express Implementation:** Setting status codes alongside responses:
  - `res.status(201).json({ status: 'Success', id: newId });`
  - `res.status(400).json({ status: 'Error', message: 'All fields required' });`
- **Developer Tooling (`nodemon`):**
  - Installing nodemon as a dev dependency: `npm install -D nodemon`.
  - Adding `"dev": "nodemon index.js"` to `package.json` scripts to automatically restart the server on file edits without manual terminal restarts.

---

## Video 18: Getting Started with MongoDB
- **NoSQL Document Database Fundamentals:**
  - Comparing Relational DBs (Databases $\rightarrow$ Tables $\rightarrow$ Rows/Columns) with NoSQL Document DBs (Databases $\rightarrow$ Collections $\rightarrow$ Documents).
- **JSON / BSON Data Storage:** Why MongoDB stores data in Binary JSON (BSON) for speed, efficiency, and rich data type support.
- **MongoDB Tools & Setup:**
  - Running MongoDB community server locally.
  - Visual database inspection with **MongoDB Compass**.
- **Mongo Shell (`mongosh`) CLI Commands:**
  - `show dbs` (lists databases).
  - `use <db-name>` (switches active database).
  - `db.createCollection('users')` (creates collection).
  - `db.users.insertOne({ name: 'Piyush', email: 'p@gmail.com' })` (inserts document).
  - `db.users.find()` (queries documents).

---

## Video 19: Connecting NodeJS with MongoDB (Mongoose + Express)
- **Object Data Modeling (ODM):** Using Mongoose (`npm install mongoose`) to enforce structured schemas and manage MongoDB interactions.
- **Database Connection:** Connecting asynchronously via `mongoose.connect('mongodb://127.0.0.1:27017/app-1')`.
- **Defining Schemas & Models:**
  ```javascript
  const userSchema = new mongoose.Schema({
    firstName: { type: String, required: true },
    lastName: { type: String },
    email: { type: String, required: true, unique: true },
    jobTitle: { type: String }
  }, { timestamps: true });

  const User = mongoose.model('user', userSchema);
  ```
- **Async/Await CRUD in Express Routes:**
  - Create: `await User.create(req.body);`
  - Read All: `await User.find({});`
  - Read by ID: `await User.findById(req.params.id);`
  - Update: `await User.findByIdAndUpdate(req.params.id, req.body);`
  - Delete: `await User.findByIdAndDelete(req.params.id);`

---

## Video 20: Model View Controller (MVC) in NodeJS
- **Architectural Refactoring:** Decoupling a bloated monolithic `index.js` into clean, maintainable layers of concern:
  - `models/`: Mongoose schemas and database models (e.g., `user.js`).
  - `controllers/`: Core request handling and business logic (e.g., `handleGetAllUsers`, `handleCreateNewUser`).
  - `routes/`: Endpoint path mappings using `express.Router()` (e.g., `user.js`).
  - `middlewares/`: Custom request interceptors.
  - `connection.js`: Standalone MongoDB connection logic (`connectMongoDb`).
- **Express Router Modularization:** Binding sub-routes cleanly: `app.use('/api/users', userRouter);`.

---

## Video 21: Create a Custom URL Shortener using Node.JS and MongoDB
- **Real-World Backend Architecture Project:** Building a production URL shortening engine.
- **Data Modeling (`URL` Schema):**
  - `shortId`: Unique, indexed 8-character string identifier.
  - `redirectURL`: Original destination URL string.
  - `visitHistory`: Array of click analytics objects containing timestamps (`[{ timestamp: Number }]`).
- **Collision-Resistant ID Generation:** Using `nanoid` or `shortid` to generate short URL keys.
- **Redirection & Real-Time Analytics:**
  - `GET /:shortId`: Uses `findOneAndUpdate` to append `Date.now()` to `visitHistory` and redirects the user with `res.redirect(entry.redirectURL)`.
  - `GET /analytics/:shortId`: Returns total click counts (`visitHistory.length`) and exact visit timestamps.

---

## Video 23: Building Node.js Authentication from Scratch (Stateful Sessions)
- **Authentication Fundamentals:** Verifying user identity via email and password credentials.
- **Stateful (Session-Based) Architecture:**
  - Server maintains an in-memory session map or cache: `sessionId` $\rightarrow$ `userObject`.
  - Generating unique session keys using `uuid` (`uuidv4()`).
  - Sending `sessionId` to the client in response cookies (`res.cookie('uid', sessionId)`).
- **Authentication Middleware:**
  - Extracts incoming `sessionId` from request cookies.
  - Looks up user record in the server session map.
  - Attaches active user to `req.user` and calls `next()`.
- **Scaling Bottleneck of Stateful Auth:** In-memory session maps fail when scaling horizontally across multiple server instances without centralized session stores (like Redis).

---

## Video 24: JWT Authentication in NodeJS (Stateless)
- **Stateless Authentication Architecture:** The server does not store session states in memory. Any server instance in a cluster can verify incoming tokens independently.
- **Anatomy of a JSON Web Token (JWT):**
  - **Header:** Signing algorithm (`HS256`) and token type (`JWT`).
  - **Payload:** User claims (`_id`, `email`, `role`). Base64Url-encoded (not encrypted; passwords must never be stored here).
  - **Signature:** `HMACSHA256(base64UrlEncode(header) + "." + base64UrlEncode(payload), secretKey)` ensuring data integrity.
- **`jsonwebtoken` Library Usage:**
  - Generating tokens: `jwt.sign({ _id: user._id, email: user.email }, SECRET_KEY);`
  - Verifying tokens in middleware: `const decoded = jwt.verify(token, SECRET_KEY);`

---

## Video 25: What are Cookies in NodeJS?
- **Cookies vs. Authorization Headers:**
  - **Cookies:** Stored automatically by web browsers; automatically attached to every subsequent request matching the target domain.
  - **Authorization Headers (`Bearer <token>`):** Standard for mobile apps and single-page applications (React); requires manual attachment via client-side request interceptors.
- **Cookie Setup in Express:**
  - Setting cookies: `res.cookie('uid', token, { httpOnly: true, maxAge: 86400000 });`
  - Reading incoming cookies using `cookie-parser`: `app.use(cookieParser())` and accessing `req.cookies.uid`.
- **Hybrid Auth Middleware:** Designing flexible auth middleware that checks both `req.cookies?.uid` and `req.headers['authorization']` so both browser and mobile/API clients are supported.

---

## Video 26: Authorization in NodeJS (Role-Based Access Control - RBAC)
- **Authentication vs. Authorization:**
  - Authentication: Identity verification (*"Who are you?"*).
  - Authorization: Permission check (*"Are you allowed to perform this action?"*).
- **Role Modeling:** Adding a `role` field to the User Schema (`role: { type: String, required: true, default: 'NORMAL' }`).
- **Higher-Order Role Guard Middleware:**
  ```javascript
  function restrictTo(roles = []) {
    return function (req, res, next) {
      if (!req.user) return res.redirect('/login');
      if (!roles.includes(req.user.role)) return res.status(403).end('UnAuthorized');
      return next();
    };
  }
  ```
- **Protecting Endpoints:** Restricting admin routes to `restrictTo(['ADMIN'])` while allowing general routes to `restrictTo(['NORMAL', 'ADMIN'])`.

---

## Video 28: Uploading Files with NodeJS and Multer
- **Multipart Data Handling:** Why standard body parsers fail on file streams, requiring `enctype="multipart/form-data"`.
- **Multer Middleware Setup (`npm install multer`):**
  - Custom storage engine configuration using `multer.diskStorage`:
    ```javascript
    const storage = multer.diskStorage({
      destination: (req, file, cb) => cb(null, './uploads'),
      filename: (req, file, cb) => cb(null, `${Date.now()}-${file.originalname}`)
    });
    const upload = multer({ storage });
    ```
- **Handling Upload Requests:**
  - Single file upload: `upload.single('profileImage')` (file data accessible via `req.file`).
  - Accessing metadata: `req.file.path`, `req.file.filename`, `req.file.mimetype`.
- **Serving Uploaded Static Media:** Exposing upload folders via `app.use('/uploads', express.static('uploads'))`.

---

## Video 29: Project Setup & Secure Password Hashing (Blogging App Backend)
- **Enterprise Password Security:** Never storing plaintext passwords in databases.
- **Salted Password Hashing using Native `crypto` Module:**
  - Generating random 16-byte cryptographic salts: `crypto.randomBytes(16).toString('hex')`.
  - Hashing with HMAC SHA-256: `crypto.createHmac('sha256', salt).update(password).digest('hex')`.
- **Mongoose Pre-Save Lifecycle Hooks:**
  ```javascript
  userSchema.pre('save', function (next) {
    if (!this.isModified('password')) return next();
    const salt = crypto.randomBytes(16).toString('hex');
    const hashedPassword = crypto.createHmac('sha256', salt).update(this.password).digest('hex');
    this.salt = salt;
    this.password = hashedPassword;
    next();
  });
  ```
- **Custom Schema Statics:** Encapsulating authentication logic into reusable model methods: `userSchema.static('matchPasswordAndGenerateToken', ...)`.

---

## Video 30: Authentication & Mongoose Relational Data Modeling (Blogging App Backend)
- **Relational Referencing in MongoDB:**
  ```javascript
  const blogSchema = new mongoose.Schema({
    title: { type: String, required: true },
    body: { type: String, required: true },
    coverImageURL: { type: String },
    createdBy: { type: mongoose.Schema.Types.ObjectId, ref: 'user' }
  }, { timestamps: true });
  ```
- **Population (`populate`):** Executing foreign-key style joins in MongoDB via Mongoose: `Blog.find({}).populate('createdBy')` to fetch full author details alongside blog posts.
- **Global Auth Verification Middleware:** Building request interceptors to validate authentication cookies, decode user tokens, and attach `req.user`.

---

## Video 32: Deploy NodeJS Application on AWS (EC2 & Ubuntu)
- **AWS Cloud Setup:**
  - Launching an AWS EC2 instance running Ubuntu Server LTS.
  - Creating and downloading an SSH Key Pair (`.pem`).
  - Configuring AWS Security Groups: Opening Port 22 (SSH), Port 80 (HTTP), Port 443 (HTTPS), and application ports (e.g., 8000).
- **Remote Server Management via SSH:**
  - Connecting from local terminal: `ssh -i key.pem ubuntu@<ec2-public-ip>`.
  - Installing Node.js, npm, and Git on Ubuntu (`sudo apt update && sudo apt install nodejs npm git`).
  - Cloning project repository, installing dependencies, configuring dynamic environment variables (`process.env.PORT`), and running backend services.

---

## Video 33: WebSocket in NodeJS | Socket.IO (Real-Time Messaging)
- **HTTP Polling vs. WebSockets:**
  - HTTP Polling: Client repeatedly opens and closes HTTP connections with heavy header overhead.
  - WebSockets: Persistent, full-duplex, bi-directional TCP connection established via an initial HTTP handshake.
- **Socket.IO Integration (`npm install socket.io`):**
  - Binding Socket.IO to the native HTTP server: `const io = new Server(server)`.
  - Managing connection lifecycles:
    ```javascript
    io.on('connection', (socket) => {
      console.log('A user connected:', socket.id);
      socket.on('user-message', (message) => {
        io.emit('message', message); // Broadcast to all connected clients
      });
      socket.on('disconnect', () => console.log('User disconnected'));
    });
    ```
- **Event-Driven Architecture:** Emitting custom named events (`socket.emit`), handling events (`socket.on`), and broadcasting messages to all connected clients (`io.emit`).

---

## Video 34: NodeJS Streams
- **Memory Management in High-Scale Systems:**
  - Reading large files (e.g., 500MB+) via `fs.readFile` loads the entire file into server RAM at once, causing memory spikes and server crashes under concurrent traffic (demonstrated live with `express-status-monitor`).
- **Streaming Architecture:**
  - Processing data chunk-by-chunk in small buffer segments (e.g., 64KB chunks).
  - Keeps server memory consumption minimal and constant ($O(1)$) regardless of total file size.
- **The 4 Core Stream Types:**
  - **Readable Stream:** Data source (`fs.createReadStream()`, HTTP `req`).
  - **Writable Stream:** Data destination (`fs.createWriteStream()`, HTTP `res`).
  - **Duplex Stream:** Both readable and writable (e.g., network sockets).
  - **Transform Stream:** Modifies data while reading/writing (e.g., `zlib.createGzip()`).
- **Piping Streams:** Connecting readable sources directly to writable destinations using `.pipe()`:
  ```javascript
  fs.createReadStream('./large-file.txt').pipe(res);
  ```

---

## Video 35: Scaling NodeJs Applications Using the Cluster Module
- **The Single-Core Bottleneck:** Node.js executes on a single CPU core by default, leaving multi-core servers (4, 8, 16+ cores) underutilized.
- **The Native `cluster` Module:**
  - Detecting available physical CPU cores: `const totalCPUs = os.cpus().length;`
  - Forking master processes into worker child processes: `cluster.fork();`
- **Primary (Master) vs. Worker Architecture:**
  - `cluster.isPrimary`: Manages process creation and forks workers based on CPU core count.
  - `cluster.isWorker`: Runs the actual Express web server instance.
- **Shared Network Ports:** All worker processes share the same listening port (e.g., Port 8000); the underlying operating system distributes incoming TCP connections among workers using a round-robin algorithm.

---

## Video 36: What is Nginx? (Reverse Proxy Architecture)
- **Nginx Fundamentals:** An asynchronous, event-driven, high-performance web server, reverse proxy, and load balancer.
- **Forward Proxy vs. Reverse Proxy (Essential System Design Concept):**
  - **Forward Proxy:** Sits between clients and the internet; masks client identities, handles client-side caching, and bypasses local network restrictions.
  - **Reverse Proxy:** Sits between the internet and backend web servers; masks internal server architecture and private IP addresses, terminates SSL, handles caching, and balances load across multiple backend Node.js instances.

---

## Video 37: Install and Setup Nginx (Linux Service & Configuration)
- **Linux Installation:** Installing Nginx via package manager (`sudo apt install nginx`) or running inside a Linux Docker container.
- **Service Management Commands:**
  - `systemctl start nginx`
  - `systemctl stop nginx`
  - `systemctl restart nginx`
  - `systemctl status nginx`
- **Configuration Hierarchy:** Navigating and editing `/etc/nginx/nginx.conf` and site blocks in `/etc/nginx/sites-available/default`.
- **Config Syntax Validation:** Validating configuration syntax before reloading using `nginx -t`.

---

## Video 38: Serve Static Content with Nginx
- **Static File Offloading:** Why routing static asset requests (images, CSS, JS bundles) through Node’s single-threaded event loop wastes CPU cycles; Nginx uses the Linux kernel’s zero-copy `sendfile` system call to stream files straight from disk to the network card.
- **Nginx Location Blocks:**
  ```nginx
  server {
      listen 80;
      server_name mydomain.com;

      location / {
          root /var/www/html;
          index index.html;
      }

      location /images/ {
          root /data;
      }
  }
  ```

---

## Video 39: Full Node.js Deployment - NGINX, SSL With Lets Encrypt
- **Nginx Reverse Proxy Configuration for Node.js:**
  - Forwarding public internet traffic from Port 80 to an internal Node.js port (e.g., 8000):
    ```nginx
    server {
        listen 80;
        server_name mydomain.com;

        location / {
            proxy_pass http://localhost:8000;
            proxy_http_version 1.1;
            proxy_set_header Upgrade $http_upgrade;
            proxy_set_header Connection 'upgrade';
            proxy_set_header Host $host;
            proxy_cache_bypass $http_upgrade;
        }
    }
    ```
- **SSL / TLS Certificate Setup with Let’s Encrypt:**
  - Installing Certbot: `sudo apt install certbot python3-certbot-nginx`.
  - Automatically obtaining certificates and configuring Nginx: `sudo certbot --nginx -d mydomain.com`.
  - Certbot automatically adds HTTPS port 443 bindings and configures HTTP-to-HTTPS 301 redirections.

---

## Appendix: Excluded Non-MERN Videos (12 Videos)

The following 12 videos from the 48-video playlist are excluded from the core MERN curriculum as they cover different stacks, bot scripting, or serverless architectures:

| Video # & Title | What Is Taught | Reason for Exclusion from MERN Track |
| :--- | :--- | :--- |
| **Video 22: Server Side Rendering with EJS and Node.JS** | Embedded JavaScript (EJS) templating engine, server-rendered views. | **Traditional SSR Templating:** In the MERN stack, the UI is decoupled as a React.js Single Page Application (SPA) consuming JSON REST APIs. |
| **Video 27: Creating Discord Bot in NodeJS** | Discord API, `discord.js` library, Bot gateway authentication. | **Bot Scripting:** Has no connection to web app development, REST APIs, or MERN architecture. |
| **Video 31: Complete Blog App - NodeJS, MongoDB and EJS** | Complete blog application UI rendering using EJS templates. | **EJS Templating:** Same as Video 22; uses server-rendered EJS rather than React for the presentation layer. *(Core backend auth/model logic is retained in Videos 29 & 30)*. |
| **Video 40: Serverless Framework with NodeJS** | Serverless CLI, `serverless.yml` configuration, AWS Lambda handlers. | **Serverless (FaaS):** Event-driven ephemeral cloud functions rather than persistent MERN Express/Node server daemons. |
| **Video 41: What is Serverless? \| Serverless Vs Monolith \| AWS Lambda** | Monolith vs Serverless comparison, cold starts, Lambda auto-scaling. | **Serverless (FaaS):** Architecture comparison rather than MERN stack development. |
| **Videos 42–48: Complete GraphQL Series** <br>• *Video 42: GraphQL Crash Course* <br>• *Video 43: Threads App Backend Architecture* <br>• *Video 44: Setting up GraphQL Server* <br>• *Video 45: GraphQL Prisma PostgreSQL Setup* <br>• *Video 46: Refactoring GraphQL Code* <br>• *Video 47: Authentication with GraphQL Server* <br>• *Video 48: JWT Auth & Context in GraphQL* | GraphQL SDL, Queries, Mutations, Resolvers, Apollo Server, Prisma ORM, and PostgreSQL. | **PERN / Relational Stack:** Teaches an entirely different technology stack based on Relational SQL (PostgreSQL), Prisma ORM, and GraphQL instead of MongoDB, Mongoose, and REST APIs. |
