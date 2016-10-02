//
// ApplyAnimations.h
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once
// Modify the following definitions if you need to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER              // Allow use of features specific to Windows 7 or later.
#define WINVER 0x0700       // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT        // Allow use of features specific to Windows 7 or later.
#define _WIN32_WINNT 0x0700 // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN     // Exclude rarely-used items from Windows headers

// Windows Header Files:
#include <windows.h>
#include <objbase.h>
#include <Strsafe.h>
#include <wincodec.h>

// C RunTime Header Files
#include <math.h>

// DirectComposition Header File
#include <dcomp.h>

// Direct2D and Direct3D Header Files
#include <d2d1.h>
#include <d3d11.h>


/******************************************************************
*                                                                 *
*  Macros                                                         *
*                                                                 *
******************************************************************/
template<class Interface>
inline void
SafeRelease(
    Interface **ppInterfaceToRelease
    )
{
    if (*ppInterfaceToRelease != NULL)
    {
        (*ppInterfaceToRelease)->Release();

        (*ppInterfaceToRelease) = NULL;
    }
}

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif

/******************************************************************
*                                                                 *
*  DemoApp                                                        *
*                                                                 *
******************************************************************/

class DemoApp
{
public:
    DemoApp();
    ~DemoApp();

    HRESULT Initialize();

    void RunMessageLoop();

private:
    HRESULT InitializeDirectCompositionDevice();

    HRESULT OnPaint();
    HRESULT DemoApp::OnClick();

    HRESULT CreateDeviceIndependentResources();
    HRESULT CreateDeviceResources();
    void DiscardDeviceResources();

    HRESULT LoadJPEGImage(
        ID2D1RenderTarget *pRenderTarget,
        PCWSTR fileName,
        ID2D1Bitmap **ppBitmap
        );

    HRESULT GetImageFilenames(TCHAR szDir[MAX_PATH]);
    HRESULT SetVisualOpacity(IDCompositionVisual *pVisual, float opacity);

    static LRESULT CALLBACK WndProc(
        HWND hWnd,
        UINT message,
        WPARAM wParam,
        LPARAM lParam
        );

 private:
    HWND m_hwnd;
    ID2D1Bitmap *m_pBitmap;
    int m_bitmapWidth;
    int m_bitmapHeight;
    ID2D1Factory *m_pD2DFactory;
    ID2D1HwndRenderTarget *m_pRenderTarget;
    IWICImagingFactory *m_pWICFactory;
    ID3D11Device *m_pD3D11Device;
    IDCompositionDevice *m_pDevice;
    IDCompositionTarget *m_pCompTarget;
    IDCompositionVisual *m_pVisual;
    IDCompositionSurface *m_pSurface;
    IDCompositionAnimation *m_pFadeOutAnimation;
    IDCompositionAnimation *m_pFadeInAnimation;
    IDCompositionEffectGroup *m_pEffectGroup;
    LPCTSTR m_pImageFileNames[5];
    LPCTSTR m_pImageDir;
 };
