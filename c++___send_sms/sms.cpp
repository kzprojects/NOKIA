using System;
using System.IO.Ports;
using System.Linq;

namespace GSMSMSsend
{
   class Program
   {
      // NOTE: Change this to the actual name of the port
      // where your modem is
      private const string SERIAL_PORT_NAME = "COM41";

      private static SerialPort _modemConnection;

      static void SendSms(string destination, string text)
      {
         // Turn off echo, we don't need it for this
         _modemConnection.WriteLine("ATE0");
         var response = _modemConnection.ReadExisting();

         // Set text mode
         _modemConnection.WriteLine("AT+CMGF=1");
         response = _modemConnection.ReadExisting();

         // Send the SMS
         _modemConnection.WriteLine(String.Format
            ("AT+CMGS=\"{0}\"", destination));
         response = _modemConnection.ReadExisting();

         _modemConnection.Write(text);
         _modemConnection.Write(new byte[]{26}, 0, 1);

         response = _modemConnection.ReadExisting();

         if(response.Contains("ERROR"))
         {
            Console.WriteLine("SMS Failed to send");
         }
         else
         {
            Console.WriteLine("SMS Sent");
            Console.WriteLine("Response: {0}", response);
          }
      }

      static void HelpText()
      {
         Console.WriteLine("ERROR: ");
         Console.WriteLine("\tUSage is GSMSMSSend <number>
            \"<message>\"");
         Console.WriteLine("");
         Console.WriteLine("Where <number> should be
            the phone number you wish to send to in
            international format");
         Console.WriteLine("and \"<message>\" is the text
            you wish to send (NOTE: you MUST surround it
            with quote marks)");
      }

      static void Main(string[] args)
      {
         if(args.Count() != 2)
         {
            HelpText();
            return;
         }

         var destinationNumber = args[0];
         var message = args[1];

         Console.WriteLine("About to send message to {0}",
            destinationNumber);

         _modemConnection = new SerialPort(SERIAL_PORT_NAME)
         {
            // 19200 baud, most modems will accept everything
            // from 9600 up to 115200
            BaudRate = 19200,
            // 99% of the time the port connection will be
            //8 Data bits
            DataBits = 8,
            // NO partiy
            Parity = Parity.None,
            // and 1 stop bit. Check your modem manual if
            // this doesn't work
            StopBits = StopBits.One
         };
         _modemConnection.Open();

         SendSms(destinationNumber, message);

         _modemConnection.Close();

      }

   }
}
