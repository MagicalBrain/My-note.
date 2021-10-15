# Customizing Built-in WixUI Dialog Sets

The built-in WixUI dialog sets can be customized in the following ways:

+ Specifying a product-specific license agreement file.
+ Specifying product-specific setup UI bitmaps.
+ Adding an optional checkbox and optional text to the ExitDlg.
+ Customizing the text displayed in built-in dialogs.
+ Changing the UI sequence of a built-in dialog set.
+ Inserting a custom dialog into a built-in dialog set.

## Specifying a license file

WixUIExtension.dll includes a default, placeholder license agreement. To specify your product's license, override the default by specifying a WiX variable named WixUILicenseRtf with the value of an RTF file that contains your license text. You can define the variable in your WiX authoring:

```xml
<WixVariable Id="WixUILicenseRtf" Value="bobpl.rtf" />
```

Alternatively, you can define the variable using the -d switch when running light:

```xml
light -ext WixUIExtension -cultures:en-us -dWixUILicenseRtf=bobpl.rtf Product.wixobj -out Product.msi
```

The file you specify must be in a directory light is looking in for files. Use the -b switch to add directories.

There is a known issue with the rich text control used to display the text of the license file that can cause the text to appear blank until the user scrolls down in the control. This is typically caused by complex RTF content (such as the RTF generated when saving an RTF file in Microsoft Word). If you run into this behavior in your setup UI, one of the following workarounds will fix it in most cases:

+ Open your RTF file in WordPad and save it from there in order to remove the complex RTF content from the file. After saving it, rebuild your MSI.
+ Use a dialog set other than the WixUI_Minimal set. This problem typically only occurs when the license agreement screen is the first one displayed during setup, which only happens with the WixUI_Minimal dialog set.

## Replacing the default bitmaps

The WixUI dialog library includes default bitmaps for the background of the welcome and completion dialogs and the top banner of the other dialogs. You can replace those bitmaps with your own for product branding purposes. To replace default bitmaps, specify WiX variable values with the file names of your bitmaps, just like when replacing the default license text.


|Variable name|	Description|	Dimensions|
|--|--|--|
|WixUIBannerBmp	|Top banner|	493 × 58|
|WixUIDialogBmp|	Background bitmap used on the welcome and completion dialogs|	493 × 312|
|WixUIExclamationIco|	Exclamation icon on the WaitForCostingDlg	|32 × 32|
|WixUIInfoIco|	Information icon on the cancel and error dialogs|	32 × 32|
|WixUINewIco|	Button glyph on the BrowseDlg|	16 × 16|
|WixUIUpIco|	Button glyph on the BrowseDlg|	16 × 16|

## Customizing the ExitDlg

The ExitDlg is the [dialog in the built-in WixUI dialog sets][dialog in the built-in WixUI dialog sets] that is displayed at the end of a successful setup. The ExitDlg supports showing both optional, customizable text and an optional checkbox.

[dialog in the built-in WixUI dialog sets]:https://wixtoolset.org//documentation/manual/v3/wixui/dialog_reference/wixui_dialogs.html

See [How To: Run the Installed Application After Setup][How To: Run the Installed Application After Setup] for an example of how to show a checkbox on the ExitDlg.

[How To: Run the Installed Application After Setup]:https://wixtoolset.org/documentation/manual/v3/howtos/ui_and_localization/run_program_after_install.html

To show optional text on the ExitDlg, set the WIXUI_EXITDIALOGOPTIONALTEXT property to the string you want to show. For example:

```xml
<Property Id="WIXUI_EXITDIALOGOPTIONALTEXT" Value="Thank you for installing this product." />
```

The optional text has the following behavior:

+ The optional text is displayed as literal text, so properties surrounded by square brackets such as [ProductName] will not be resolved. If you need to include property values in the optional text, you must schedule a custom action to set the property. For example:

```xml
<CustomAction Id="CA_Set_WIXUI_EXITDIALOGOPTIONALTEXT" Property="WIXUI_EXITDIALOGOPTIONALTEXT" Value="Thank you for installing [ProductName]."/>
  <InstallUISequence>
    <Custom Action="CA_Set_WIXUI_EXITDIALOGOPTIONALTEXT" After="FindRelatedProducts">NOT Installed</Custom>
  </InstallUISequence>
```

+ Long strings will wrap across multiple lines.
+ The optional text is only shown during initial installation, not during maintenance mode or uninstall.

## Customizing the text in built-in dialogs

All text displayed in built-in WixUI dialog sets can be overridden with custom strings if desired. In order to do so, you must add a string to your product's WiX localization (.wxl) file that has the same Id value as the string that you want to override. You can find the WixUI string Id values by looking in the file named WixUI_en-us.wxl in the WiX source code.

For example, to override the descriptive text on the WelcomeDlg, you would add the following to a .wxl file in your project:

```xml
<String Id="WelcomeDlgDescription">This is a custom welcome message. Click Next to continue or Cancel to exit.</String>
```

## Changing the UI sequence of a built-in dialog set

Each of the WixUI dialog sets contains a pre-defined set of dialogs that will be displayed in a specific order. Information about the dialogs included in each built-in WixUI dialog set can be found in the WixUI Dialog Library Reference.

It is possible to change the default sequence of a built-in dialog set. To do so, you must copy the contents of the <Fragment/> that includes the definition of the dialog set that you want to customize from the WiX source code to your project. Then, you must modify the <Publish/> elements to define the exact dialog sequence that you want in your installation experience.

For example, to remove the LicenseAgreementDlg from the WixUI_InstallDir dialog set, you would do the following:

1. Copy the full contents of the <Fragment/> defined in WixUI_InstallDir.wxs in the WiX source code to your project.
Remove the <Publish/> elements that are used to add Back and Next events for the LicenseAgreementDlg.
Change the <Publish/> element that is used to add a Next event to the WelcomeDlg to go to the InstallDirDlg instead of the LicenseAgreementDlg. For example:
