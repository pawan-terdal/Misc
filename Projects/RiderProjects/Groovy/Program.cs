using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;


namespace Groovy
{
    internal class Program
    {
        static string ExtractTokenFromJson(string json)
        {
            string token = null;
            Match match = Regex.Match(json, ".*\"access_token\":\"(?<token>.*?)\".*", RegexOptions.IgnoreCase);
            if (match.Success)
            {
                token = match.Groups["token"].Value;
            }
            return token;
        }
        static string SendRequest(string method, string service, string postData)
        {

            string responseString = null;
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(service);

            UTF8Encoding encoding = new UTF8Encoding();
            byte[] data = encoding.GetBytes(postData);

            request.Method = method;
            request.ContentType = "application/x-www-form-urlencoded";
            request.ContentLength = data.Length;

            using (Stream stream = request.GetRequestStream())
            {
                stream.Write(data, 0, data.Length);
            }

            using (HttpWebResponse response = (HttpWebResponse)request.GetResponse())
            {
                responseString = new StreamReader(response.GetResponseStream()).ReadToEnd();
            }

            return responseString;
        }

        public static void Main(string[] args)
        {
            Console.WriteLine("Hello World");

            //authentication endpoint, must be https
            string service = "https://login.live.com/accesstoken.srf";

// your application ID as displayed on your application page on the Microsoft Application Registration Portal
            string clientId = "8ed33a3a-0470-4758-9033-5a4b32da8043";

// your Application Secret as displayed on your application page on the Microsoft Application Registration Portal
            string clientSecret = "WmZUSNB2tA5Ma25jDFLemZB";
            string clientSecretEnc = System.Uri.EscapeDataString(clientSecret);

//will be used to store the authentication token
            string token = null;
            HttpWebRequest request = null;
            HttpWebResponse response = null;

// scope used for authentication. NOTE: http. not https here!
            string scope = "app.music.xboxlive.com";
            string scopeEnc = System.Uri.EscapeDataString(scope);

            string grantType = "client_credentials";

//preparing the data for authentication
            string postData = "client_id=" + clientId + "&client_secret=" + clientSecretEnc + "&scope=" + scopeEnc + "&grant_type=" + grantType;

//send the authentication request
            string responseString = SendRequest("POST", service, postData);

//token to use to authenticate aginst the Groove API
            token = ExtractTokenFromJson(responseString);

//and the request to the API (Note: the API endpoint is https)
            request = (HttpWebRequest)WebRequest.Create("https://music.xboxlive.com/1/content/music/search?q=daft+punk");
            request.Method = WebRequestMethods.Http.Get;
            request.Accept = "application/json";
            request.Headers["Authorization"] = "Bearer " + token;
            using (response = (HttpWebResponse)request.GetResponse())
            {
                using (var sr = new StreamReader(response.GetResponseStream()))
                {
                    responseString = sr.ReadToEnd();
                }
            }
            Console.WriteLine(responseString);
        }
    }
}