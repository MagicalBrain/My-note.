# CSharp如何对 JSON 进行序列化和反序列化（封送和拆收）

## 包含的程序集

```csharp
using System.Text.Json;
using System.Text.Json.Serialization;
```

## 直接将类成员转为Json格式

假设有这么个类：

```csharp
public class WeatherForecastWithPOCOs
{
    public DateTimeOffset Date { get; set; }
    public int TemperatureCelsius { get; set; }
    public string Summary { get; set; }
    public string SummaryField;
    public IList<DateTimeOffset> DatesAvailable { get; set; }
    public Dictionary<string, HighLowTemps> TemperatureRanges { get; set; }
    public string[] SummaryWords { get; set; }
}

public class HighLowTemps
{
    public int High { get; set; }
    public int Low { get; set; }
}
```

操作代码：

```csharp
class JsonUsages
    {
        public static void Test()
        {
            string path = System.IO.Directory.GetCurrentDirectory();
            Console.WriteLine(path);

            string fileName = path + "/test4Json.json";
            WeatherForecastWithPOCOs weatherForecast = new WeatherForecastWithPOCOs();

            string jsonString = JsonSerializer.Serialize(weatherForecast);

            jsonString = JsonSerializer.Serialize(weatherForecast);
            File.WriteAllText(fileName, jsonString);
        }
    }
```

输出结果默认是不包含空格和换行的：

```bash
{"Date":"0001-01-01T00:00:00+00:00","TemperatureCelsius":0,"Summary":null,"DatesAvailable":null,"TemperatureRanges":null,"SummaryWords":null}
```

```bash
{
  "Date": "0001-01-01T00:00:00+00:00",
  "TemperatureCelsius": 0,
  "Summary": null,
  "DatesAvailable": null,
  "TemperatureRanges": null,
  "SummaryWords": null
}
```

若要对 JSON 输出进行优质打印，请将 JsonSerializerOptions.WriteIndented 设置为 true：

```csharp
/*
* 将
* string jsonString = JsonSerializer.Serialize(weatherForecast);
* 替换成以下代码
*/
var options = new JsonSerializerOptions
{
    WriteIndented = true,
};
string jsonString = JsonSerializer.Serialize(weatherForecast, options);
```

## 参考链接

[微软官方文档][Microsoft]

[Microsoft]:https://docs.microsoft.com/zh-cn/dotnet/standard/serialization/system-text-json-how-to?pivots=dotnet-5-0
