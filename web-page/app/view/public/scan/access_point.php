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