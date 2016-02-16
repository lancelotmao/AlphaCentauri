//
//  AesMgr4iOS.h
//  Test
//
//  Created by mCloud on 15/4/3.
//  Copyright (c) 2015年 mCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

// aes加密解密：密钥长度是128比特，模式：AES/ECB/NoPadding

@interface AesCrypt4iOS : NSObject

/**************************************************************/
// 用户aes加密数据
// 参数:
//			pIn-[IN]原文
//			pDest-[OUT]保存 经base64加密过的密文
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)DtmAesEncryptByUser:(NSData *)pIn pDest:(NSData **)pDest;

/**************************************************************/
// 用户aes解密数据
// 参数:
//			pIn-[IN]base64加密过的密文
//			pDest-[OUT]保存原文
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)DtmAesDecryptByUser:(NSData *)pIn pDest:(NSData **)pDest;

/**************************************************************/
// aes加密数据
// 参数:
//			pKey-[IN]密钥
//			pIn-[IN]原文
//			pDest-[OUT]保存 经base64加密过的密文
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)DtmAesEncrypt:(NSData *)pKey pIn:(NSData *)pIn pDest:(NSData **)pDest;

/**************************************************************/
// aes解密数据
// 参数:
//			pKey-[IN]密钥
//			pIn-[IN]base64加密过的密文
//			pDest-[OUT]保存原文
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)DtmAesDecrypt:(NSData *)pKey pIn:(NSData *)pIn pDest:(NSData **)pDest;

@end
