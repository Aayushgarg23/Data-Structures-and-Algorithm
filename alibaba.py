import requests
import time
import json
import hashlib

class AlibabaDataEngine:
    def __init__(self, app_key, app_secret, session_key):
        self.url = "https://gw.api.taobao.com/router/rest" # Alibaba Gateway
        self.app_key = app_key
        self.app_secret = app_secret
        self.session_key = session_key

    def generate_sign(self, params):
        """Generates the MD5 signature required by Alibaba's API security."""
        params_str = self.app_secret
        for k in sorted(params.keys()):
            params_str += f"{k}{params[k]}"
        params_str += self.app_secret
        return hashlib.md5(params_str.encode('utf-8')).hexdigest().upper()

    def call_api(self, method, extra_params):
        """Generic handler for API requests."""
        params = {
            "method": method,
            "app_key": self.app_key,
            "session": self.session_key,
            "timestamp": time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()),
            "format": "json",
            "v": "2.0",
            "sign_method": "md5"
        }
        params.update(extra_params)
        params["sign"] = self.generate_sign(params)
        
        response = requests.post(self.url, data=params)
        return response.json()

    def get_product_details(self, product_id):
        """Fetches full item details: Price, Images, Description."""
        return self.call_api("alibaba.icbu.product.get", {
            "product_id": product_id,
            "fields": "name,price,description,images,attributes,category_id"
        })

# --- CONFIGURATION ---
CREDENTIALS = {
    "app_key": "YOUR_APP_KEY",
    "app_secret": "YOUR_APP_SECRET",
    "session_key": "YOUR_SESSION_TOKEN"
}

def main():
    engine = AlibabaDataEngine(**CREDENTIALS)
    
    # 1. Example: Fetch specific item data
    # In production, you would loop through a list of IDs from alibaba.icbu.product.list
    target_product_id = "123456789" 
    print(f"--- Extracting Product ID: {target_product_id} ---")
    
    data = engine.get_product_details(target_product_id)
    
    # 2. Displaying the data in VS Code Console
    print(json.dumps(data, indent=4))
    
    # 3. Saving to a local JSON file for extraction
    with open("extracted_alibaba_data.json", "w") as f:
        json.dump(data, f, indent=4)
        print("\n[SUCCESS] Data extracted and saved to 'extracted_alibaba_data.json'")

if __name__ == "__main__":
    main()