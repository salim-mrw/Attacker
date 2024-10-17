<!doctype html>
<html lang="en" data-theme="light">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="theme-color" media="(prefers-color-scheme: light)" content="var(--mode-color)" />
	<meta name="theme-color" media="(prefers-color-scheme: dark)" content="var(--mode-color)" />
    <title>Attacker</title>
    <link rel="stylesheet" href="style.css">
    <link rel="icon" href="logo.png">
  </head>
  <body class="pt-0 pb-5 bg-dark text-light">
    <div id="loader" class="d-flex wh-100">
        <div class="sub-loader"></div>
    </div>
    <nav>
        <div class="nav-list">
            <span id="list" class="cursor-pointer"><svg height="24px" viewBox="0 -960 960 960" width="24px" fill="#0dcaf0"><path d="M784-120 532-372q-30 24-69 38t-83 14q-109 0-184.5-75.5T120-580q0-109 75.5-184.5T380-840q109 0 184.5 75.5T640-580q0 44-14 83t-38 69l252 252-56 56ZM380-400q75 0 127.5-52.5T560-580q0-75-52.5-127.5T380-760q-75 0-127.5 52.5T200-580q0 75 52.5 127.5T380-400Z"/></svg></span>
            <span id="mode" class="cursor-pointer"><svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-sun" viewBox="0 0 16 16">
                <path d="M8 11a3 3 0 1 1 0-6 3 3 0 0 1 0 6m0 1a4 4 0 1 0 0-8 4 4 0 0 0 0 8M8 0a.5.5 0 0 1 .5.5v2a.5.5 0 0 1-1 0v-2A.5.5 0 0 1 8 0m0 13a.5.5 0 0 1 .5.5v2a.5.5 0 0 1-1 0v-2A.5.5 0 0 1 8 13m8-5a.5.5 0 0 1-.5.5h-2a.5.5 0 0 1 0-1h2a.5.5 0 0 1 .5.5M3 8a.5.5 0 0 1-.5.5h-2a.5.5 0 0 1 0-1h2A.5.5 0 0 1 3 8m10.657-5.657a.5.5 0 0 1 0 .707l-1.414 1.415a.5.5 0 1 1-.707-.708l1.414-1.414a.5.5 0 0 1 .707 0m-9.193 9.193a.5.5 0 0 1 0 .707L3.05 13.657a.5.5 0 0 1-.707-.707l1.414-1.414a.5.5 0 0 1 .707 0m9.193 2.121a.5.5 0 0 1-.707 0l-1.414-1.414a.5.5 0 0 1 .707-.707l1.414 1.414a.5.5 0 0 1 0 .707M4.464 4.465a.5.5 0 0 1-.707 0L2.343 3.05a.5.5 0 1 1 .707-.707l1.414 1.414a.5.5 0 0 1 0 .708"/>
              </svg></span>
            <ul>
                <li><a href="#scan"><svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-search" viewBox="0 0 16 16">
                    <path d="M11.742 10.344a6.5 6.5 0 1 0-1.397 1.398h-.001q.044.06.098.115l3.85 3.85a1 1 0 0 0 1.415-1.414l-3.85-3.85a1 1 0 0 0-.115-.1zM12 6.5a5.5 5.5 0 1 1-11 0 5.5 5.5 0 0 1 11 0"/>
                  </svg></a></li>
                <li><a href="#attack"><svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-lightning-charge" viewBox="0 0 16 16"><path d="M11.251.068a.5.5 0 0 1 .227.58L9.677 6.5H13a.5.5 0 0 1 .364.843l-8 8.5a.5.5 0 0 1-.842-.49L6.323 9.5H3a.5.5 0 0 1-.364-.843l8-8.5a.5.5 0 0 1 .615-.09zM4.157 8.5H7a.5.5 0 0 1 .478.647L6.11 13.59l5.732-6.09H9a.5.5 0 0 1-.478-.647L9.89 2.41z"/></svg></a></li>
                <li><a href="#about"><svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-info-lg" viewBox="0 0 16 16"><path d="m9.708 6.075-3.024.379-.108.502.595.108c.387.093.464.232.38.619l-.975 4.577c-.255 1.183.14 1.74 1.067 1.74.72 0 1.554-.332 1.933-.789l.116-.549c-.263.232-.65.325-.905.325-.363 0-.494-.255-.402-.704zm.091-2.755a1.32 1.32 0 1 1-2.64 0 1.32 1.32 0 0 1 2.64 0"/></svg></a></li>
            </ul>
        </div>
    </nav>
    <div class="container-fluid">
        <section id="scan" class="wh-aut0 text-align-left">
            <form action="" method="GET" name="scanForm">
                <div class="box border-left-info mt-2 mb-2">  
                    <h5 class="text-info">Scan</h3>
                </div>
                <button type="button" name="scan">Scan</button>
                <button type="button" name="clear">Clear</button>
                <h4 class="text text-info">Setting</h4>
                <div class="d-grid">
                    <label class="text-light mb-2" for="chanal">Channel
                        <select class="text-info" name="chanal" id="chanal">
                            <option value="All">All</option>
                            <option value="1">1</option>
                            <option value="2">2</option>
                            <option value="3">3</option>
                        </select>
                    </label>
                    <label class="text-light mb-2" for="Frequency">Frequency
                        <select class="text-info" name="Frequency" id="Frequency">
                            <option value="All">All</option>
                            <option value="1">2.4 GHZ</option>
                            <option value="2">5.0 GHZ</option>
                        </select>
                    </label>
                    <label class="text-light mb-2" for="devices">Devices
                        <select class="text-info" name="devices" id="devices">
                            <option value="Devices">No Limit</option>
                            <option value="1">5</option>
                            <option value="2">10</option>
                        </select>
                    </label>
                </div>
                <table class="text table text-info mt-1 mb-5">
                    <caption class="text text-info">Access Point</caption>
                    <thead>
                        <tr class="table-info text-info">
                            <th scope="col">#</th>
                            <th scope="col">SSID</th>
                            <th scope="col">MAC</th>
                            <th scope="col">RSSI</th>
                            <th scope="col">Security</th>
                            <th scope="col">Channel</th>
                            <th scope="col">Type</th>
                            <th scope="col">Vendor</th>
                            <th><input id="apAll" type="checkbox" name="apAll"></th>
                        </tr>
                    </thead>
                    <tbody id="aptbody">
                    </tbody>
                </table>
                <button type="button" name="reloadSTA">Reload</button>
                <table class="text table text-info mt-1 mb-5">
                    <caption class="text text-info">Station</caption>
                    <thead>
                        <tr class="table-info text-info">
                            <th scope="col">#</th>
                            <th scope="col">Station</th>
                            <th scope="col">IP</th>
                            <th scope="col">MAC</th>
                            <th scope="col">Pkts</th>
                            <th scope="col">Channel</th>
                            <th scope="col">Access Point</th>
                            <th scope="col">Last Seen</th>
                            <th><input type="checkbox" name="staTarget"></th>
                        </tr>
                    </thead>
                    <tbody id="statbody">
                    </tbody>
                </table>
            </form>
        </section>
        <section id="attack" class="wh-aut0 text-align-left">
            <form action="" method="GET" name="attackForm">
                <div class="box border-left-info mt-2 mb-2">  
                    <h5 class="text-info">Attack</h3>
                </div> 
                <button type="button" name="reloadAttack">Reload</button>
                <table class="text table text-info mt-5 mb-5">
                    <thead>
                        <tr class="table-info text-info">
                            <th scope="col">Attack</th>
                            <th scope="col" class="text-align-center">Targets</th>
                            <th scope="col" class="text-align-center">Status</th>
                            <th scope="col" class="text-align-center">Description</th>
                        </tr>
                    </thead>
                    <tbody id="attacktbody">
                    </tbody>
                </table>
            </form>
        </section>
        <section id="about" class="wh-100 about-text d-flex"> 
            <img src="logo.png" alt="icon" class="logo" width="300px" height="280px" loading="lazy"/>
            <p class="text-light text-align-left">
                <span><a href="https://attacker.org" target="_blank" class="text-info">attacker.com</a></span> as origenal website<br /> It is made by 
                <span><a href="https://salim-mrw.com" target="_blank" class="text-info">Salim Marwan</a></span><br /> From 
                <span><a href="https://nit21.net" target="_blank" class="text-info">NIT</a></span>
                <br /> V 1.0
            </p>
        </section>
    </div>
    <script src="script.js"></script>
  </body>
</html>