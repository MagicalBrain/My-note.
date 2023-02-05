# C++转译成CSharp变量对照表

C++ ---------------------- C#

LDWORD ----------------IntPtr

LLONG-------------------Intptr

bool ---------------------bool、byte

HANDLE(void   *)--------------System.IntPtr

void*-------------------------------IntPtr

Byte(unsigned   char)-------------System.Byte

SHORT(short)----------------------System.Int16

WORD(unsigned   short)---------System.UInt16

INT(short int) -----------------------System.Int16

INT(long int)-------------------------System.Int32

UINT(unsigned short int) --------System.UInt16

UINT(unsigned long int) ---------System.UInt32

LONG(long)-------------------------System.Int32

ULONG(unsigned   long)--------System.UInt32

DWORD(unsigned   long)-------System.UInt32

DECIMAL                                   ----    System.Decimal
BOOL(long)                                ----    System.Boolean
CHAR(char)                                ----    System.Char
LPSTR(char   *)                           ----    System.String
LPWSTR(wchar_t   *)                       ----    System.String
LPCSTR(const   char   *)                  ----    System.String
LPCWSTR(const   wchar_t   *)              ----    System.String
PCAHR(char   *)                           ----    System.String
BSTR                                      ----    System.String
FLOAT(float)                              ----    System.Single（float）
DOUBLE(double)                            ----    System.Double
VARIANT                                   ----    System.Object
PBYTE(byte   *)                           ----    System.Byte[]
BSTR                                      ----    StringBuilder
LPCTSTR                                   ----    StringBuilder
LPCTSTR                                   ----    string
LPTSTR                                    ----    [MarshalAs(UnmanagedType.LPTStr)] string
LPTSTR 输出变量名                         ----    StringBuilder 输出变量名
LPCWSTR                                   ----    IntPtr
BOOL                                      ----    bool 
HMODULE                                   ----    IntPtr  
HINSTANCE                                 ----    IntPtr
结构体                                    ----    public struct 结构体{};
结构体 **变量名                           ----    out 变量名   //C#中提前申明一个结构体实例化后的变量名
结构体 &变量名                            ----    ref 结构体 变量名
WORD                                      ----    ushort
DWORD                                     ----    uint
DWORD                                     ----    int
UCHAR                                     ----    int
UCHAR                                     ----    byte
UCHAR*                                    ----    string
UCHAR*                                    ----    IntPtr
GUID                                      ----    Guid
Handle                                    ----    IntPtr
HWND                                      ----    IntPtr
DWORD                                     ----    int
COLORREF                                  ----    uint


unsigned char                             ----    byte
unsigned char *                           ----    ref byte
unsigned char *                           ----    [MarshalAs(UnmanagedType.LPArray)] byte[]
unsigned char *                           ----    [MarshalAs(UnmanagedType.LPArray)] Intptr

unsigned char &                           ----    ref byte
unsigned char 变量名                      ----    byte 变量名
unsigned short 变量名                     ----    ushort 变量名
unsigned int 变量名                       ----    uint 变量名
unsigned long 变量名                      ----    ulong 变量名

char 变量名                               ----    byte 变量名   //C++中一个字符用一个字节表示,C#中一个字符用两个字节表示
char 数组名[数组大小]                     ----    MarshalAs(UnmanagedType.ByValTStr, SizeConst         =         数组大小)]        public string 数组名; ushort

char *                                    ----    string       //传入参数
char *                                    ----    StringBuilder//传出参数
char *变量名                              ----    ref string 变量名
char *输入变量名                          ----    string 输入变量名
char *输出变量名                          ----    [MarshalAs(UnmanagedType.LPStr)] StringBuilder 输出变量名

char **                                   ----    string
char **变量名                             ----    ref string 变量名
const char *                              ----    string
char[]                                    ----    string
char 变量名[数组大小]                     ----    [MarshalAs(UnmanagedType.ByValTStr,SizeConst        =        数组大小)] public string 变量名;

struct 结构体名 *变量名                   ----    ref 结构体名 变量名
委托 变量名                               ----    委托 变量名

int                                       ----    int
int                                       ----    ref int
int &                                     ----    ref int
int *                                     ----    ref int      //C#中调用前需定义int 变量名         =         0;

*int                                      ----    IntPtr
int32 PIPTR *                             ----    int32[]
float PIPTR *                             ----    float[]
      

double** 数组名                           ----    ref double 数组名
double*[] 数组名                          ----    ref double 数组名
long                                      ----    int
ulong                                     ----    int
      
UINT8 *                                   ----    ref byte       //C#中调用前需定义byte 变量名         =         new byte();      


handle                                    ----    IntPtr
hwnd                                      ----    IntPtr      
void *                                    ----    IntPtr      
void * user_obj_param                     ----    IntPtr user_obj_param
void * 对象名称                           ----    ([MarshalAs(UnmanagedType.AsAny)]Object 对象名称


      
char, INT8, SBYTE, CHAR                               ----    System.SByte
short, short int, INT16, SHORT                        ----    System.Int16
int, long, long int, INT32, LONG32, BOOL , INT        ----    System.Int32
__int64, INT64, LONGLONG                              ----    System.Int64
unsigned char, UINT8, UCHAR , BYTE                    ----    System.Byte
unsigned short, UINT16, USHORT, WORD, ATOM, WCHAR , __wchar_t             ----   System.UInt16
unsigned, unsigned int, UINT32, ULONG32, DWORD32, ULONG, DWORD, UINT      ----   System.UInt32
unsigned __int64, UINT64, DWORDLONG, ULONGLONG                            ----   System.UInt64
float, FLOAT                                                              ----   System.Single
double, long double, DOUBLE                                               ----   System.Double

//Win32 Types                                                                   ----  CLR Type
      

//Struct需要在C#里重新定义一个Struct
//CallBack回调函数需要封装在一个委托里，delegate static extern int FunCallBack(string str);

//unsigned char** ppImage替换成IntPtr ppImage
//int& nWidth替换成ref int nWidth
//int*, int&, 则都可用 ref int 对应
//双针指类型参数，可以用 ref IntPtr
//函数指针使用c++: typedef double (*fun_type1)(double); 对应 public delegate double fun_type1(double);
//char* 的操作c++: char*; 对应 StringBuilder;
//c#中使用指针:在需要使用指针的地方 加 unsafe


//unsigned   char对应public   byte


WORD                                ushort
DWORD                 uint
UCHAR                 int/byte               大部分情况都可以使用int代替,而如果需要严格对齐的话则应该用bytebyte
UCHAR*                 string/IntPtr
unsigned char*      [MarshalAs(UnmanagedType.LPArray)]byte[]/？（Intptr）
char*                 string
LPCTSTR             string
LPTSTR                 [MarshalAs(UnmanagedType.LPTStr)] string
long                     int
ulong               uint
Handle                 IntPtr
HWND                     IntPtr
void*                 IntPtr
int                      int
int*                     ref int
*int                     IntPtr
unsigned int        uint
COLORREF            uint

API与C#的数据类型对应关系表
API数据类型 类型描述               C#类型  API数据类型  类型描述              C#类型
WORD 16位无符号整数               ushort  CHAR                   字符                       char
LONG 32位无符号整数               int          DWORDLONG          64位长整数          long
DWORD 32位无符号整数              uint      HDC                   设备描述表句柄  int
HANDLE 句柄,32位整数              int          HGDIOBJ GDI     对象句柄              int
UINT 32位无符号整数               uint      HINSTANCE          实例句柄              int
BOOL 32位布尔型整数               bool      HWM                   窗口句柄              int
LPSTR 指向字符的32位指针      string  HPARAM               32位消息参数      int
LPCSTR 指向常字符的32位指针 String  LPARAM               32位消息参数      int
BYTE 字节                                    byte      WPARAM               32位消息参数      int

BOOL          =        System.Int32
BOOLEAN       =        System.Int32
BYTE          =        System.UInt16
CHAR          =        System.Int16
COLORREF      =        System.UInt32
DWORD         =        System.UInt32
DWORD32       =        System.UInt32
DWORD64       =        System.UInt64
FLOAT         =        System.Float
HACCEL        =        System.IntPtr
HANDLE        =        System.IntPtr
HBITMAP       =        System.IntPtr
HBRUSH        =        System.IntPtr
HCONV         =        System.IntPtr
HCONVLIST     =        System.IntPtr
HCURSOR       =        System.IntPtr
HDC           =        System.IntPtr
HDDEDATA      =        System.IntPtr
HDESK         =        System.IntPtr
HDROP         =        System.IntPtr
HDWP          =        System.IntPtr
HENHMETAFILE  =        System.IntPtr
HFILE         =        System.IntPtr
HFONT         =        System.IntPtr
HGDIOBJ       =        System.IntPtr
HGLOBAL       =        System.IntPtr
HHOOK         =        System.IntPtr
HICON         =        System.IntPtr
HIMAGELIST    =        System.IntPtr
HIMC          =        System.IntPtr
HINSTANCE     =        System.IntPtr
HKEY          =        System.IntPtr
HLOCAL        =        System.IntPtr
HMENU         =        System.IntPtr
HMETAFILE     =        System.IntPtr
HMODULE       =        System.IntPtr
HMONITOR      =        System.IntPtr
HPALETTE      =        System.IntPtr
HPEN          =        System.IntPtr
HRGN          =        System.IntPtr
HRSRC         =        System.IntPtr
HSZ           =        System.IntPtr
HWINSTA       =        System.IntPtr
HWND          =        System.IntPtr
INT           =        System.Int32
INT32         =        System.Int32
INT64         =        System.Int64
LONG          =        System.Int32
LONG32        =        System.Int32
LONG64        =        System.Int64
LONGLONG      =        System.Int64
LPARAM        =        System.IntPtr
LPBOOL        =        System.Int16[]
LPBYTE        =        System.UInt16[]
LPCOLORREF    =        System.UInt32[]
LPCSTR        =        System.String
LPCTSTR       =        System.String
LPCVOID       =        System.UInt32
LPCWSTR       =        System.String
LPDWORD       =        System.UInt32[]
LPHANDLE      =        System.UInt32
LPINT         =        System.Int32[]
LPLONG        =        System.Int32[]
LPSTR         =        System.String
LPTSTR        =        System.String
LPVOID        =        System.UInt32
LPWORD        =        System.Int32[]
LPWSTR        =        System.String
LRESULT       =        System.IntPtr
PBOOL         =        System.Int16[]
PBOOLEAN      =        System.Int16[]
PBYTE         =        System.UInt16[]
PCHAR         =        System.Char[]
PCSTR         =        System.String
PCTSTR        =        System.String
PCWCH         =        System.UInt32
PCWSTR        =        System.UInt32
PDWORD        =        System.Int32[]
PFLOAT        =        System.Float[]
PHANDLE       =        System.UInt32
PHKEY         =        System.UInt32
PINT          =        System.Int32[]
PLCID         =        System.UInt32
PLONG         =        System.Int32[]
PLUID         =        System.UInt32
PSHORT        =        System.Int16[]
PSTR          =        System.String
PTBYTE        =        System.Char[]
PTCHAR        =        System.Char[]
PTSTR         =        System.String
PUCHAR        =        System.Char[]
PUINT         =        System.UInt32[]
PULONG        =        System.UInt32[]
PUSHORT       =        System.UInt16[]
PVOID         =        System.UInt32
PWCHAR        =        System.Char[]
PWORD         =        System.Int16[]
PWSTR         =        System.String
REGSAM        =        System.UInt32
SC_HANDLE     =        System.IntPtr
SC_LOCK       =        System.IntPtr
SHORT         =        System.Int16
SIZE_T        =        System.UInt32
SSIZE_        =        System.UInt32
TBYTE         =        System.Char
TCHAR         =        System.Char
UCHAR         =        System.Byte
UINT          =        System.UInt32
UINT32        =        System.UInt32
UINT64        =        System.UInt64
ULONG         =        System.UInt32
ULONG32       =        System.UInt32
ULONG64       =        System.UInt64
ULONGLONG     =        System.UInt64
USHORT        =        System.UInt16
WORD          =        System.UInt16
WPARAM        =        System.IntPtr

Wtypes.h 中的非托管类型    非托管C 语言类型     托管类名           说明
HANDLE                     void*                System.IntPtr      32 位
BYTE                       unsigned char        System.Byte        8 位
SHORT                      short                System.Int16       16 位
WORD                       unsigned short       System.UInt16      16 位
INT                        int                  System.Int32       32 位
UINT                       unsigned int         System.UInt32      32 位
LONG                       long                 System.Int32       32 位
BOOL                       long                 System.Int32       32 位
DWORD                      unsigned long        System.UInt32      32 位
ULONG                      unsigned long        System.UInt32      32 位
CHAR                       char                 System.Char        用 ANSI 修饰。
LPSTR                      char*                System.String 或 System.StringBuilder  用 ANSI 修饰。
LPCSTR                     Const char*          System.String 或 System.StringBuilder  用 ANSI 修饰。
LPWSTR                     wchar_t*             System.String 或 System.StringBuilder  用 Unicode 修饰。
LPCWSTR                    Const wchar_t*       System.String 或 System.StringBuilder  用 Unicode 修饰。
FLOAT                      Float                System.Single     32 位
DOUBLE                     Double               System.Double     64 位
 
C/C++中的结构类型数据在C#下的转换
 
在做硬件对接开发的时候，会碰到SDK接口数据类型的转换，而我这一次碰到的是C/C++中的结构怎样转换到C#。
例如我们在C/C++下的结构数据如下：

typedef struct
{
    char  sLibName[ 256 ];
    char  sPathToLibrary[ 256 ];
    INT32       iEntries;
    INT32       iUsed;
    UINT16     iSort;
    UINT16     iVersion;
    BOOLEAN     fContainsSubDirectories;
    INT32       iReserved;
} LIBHEADER;

我们想把它转成C#下的结构类型如下：
    public struct LIBHEADER
    {
        public char[] sLibName;
        public char[] sPathToLibrary;
        public Int32 iEntries;
        public Int32 iUsed;
        public UInt16 iSort;
        public UInt16 iVersion;
        public Boolean fContainsSubDirectories;
        public Int32 iReserved;
    }
   
   
看上去好像没问题了，呵呵呵，其实这样是不行的，我们得再给C#编译器一些信息，告诉它一些字符数组的大小。然后它们在C#下面长得样子就变成这样：
   
   
    [StructLayout(LayoutKind.Sequential)]
    public struct LIBHEADER
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 256)]
        public char[] sLibName;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 256)]
        public char[] sPathToLibrary;
        public Int32 iEntries;
        public Int32 iUsed;
        public UInt16 iSort;
        public UInt16 iVersion;
        public Boolean fContainsSubDirectories;
        public Int32 iReserved;
    }
   
然后写一个函数负责转换。
public StructType ConverBytesToStructure<StructType>(byte[] bytesBuffer)
        {
            // 检查长度。
            if (bytesBuffer.Length != Marshal.SizeOf(typeof(StructType)))
            {
                throw new ArgumentException("bytesBuffer参数和structObject参数字节长度不一致。");
            }

            IntPtr bufferHandler = Marshal.AllocHGlobal(bytesBuffer.Length);
            for (int index = 0; index < bytesBuffer.Length; index++)
            {
                Marshal.WriteByte(bufferHandler, index, bytesBuffer[index]);
            }
            StructType structObject = (StructType)Marshal.PtrToStructure(bufferHandler, typeof(StructType));
            Marshal.FreeHGlobal(bufferHandler);
            return structObject;
        }
       
    然后我们的函数用例是这样：
            FileStream file = File.OpenRead(@"D:/Jagged Alliance 2 Gold/INSTALL.LOG");
            byte[] buffer = new byte[Marshal.SizeOf(typeof(LIBHEADER))];
            file.Read(buffer, 0, buffer.Length);
            LIBHEADER testValue = CommonTools.ConverBytesToStructure<LIBHEADER>(buffer);
             string libName = new string(testValue.sLibName);
             string pathToLibrary = new string(testValue.sPathToLibrary);
            
如果想去掉后面两句的char数组的转换哪代码如下

C#中的结构代码
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct LIBHEADER
    {
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 256)]
        public string sLibName;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 256)]
        public string sPathToLibrary;
        public Int32 iEntries;
        public Int32 iUsed;
        public UInt16 iSort;
        public UInt16 iVersion;
        public Boolean fContainsSubDirectories;
        public Int32 iReserved;
    }
