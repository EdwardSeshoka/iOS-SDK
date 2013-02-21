//
//  SinglyConnection.h
//  SinglySDK
//
//  Copyright (c) 2012-2013 Singly, Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//

#import <Foundation/Foundation.h>
#import "SinglyRequest.h"

/*!
 *
 * @available Available in Singly iOS SDK 1.2.0 and later.
 *
**/
typedef void (^SinglyConnectionRequestCompletionBlock)(id responseObject, NSError *error);

/*!
 *
 * Provides a simple wrapper around NSURLConnection that handles some basic
 * assumptions about sending requests to the Singly API. It also automatically
 * parses JSON responses and handles errors consistently.
 *
 * @available Available in Singly iOS SDK 1.2.0 and later.
 *
**/
@interface SinglyConnection : NSObject

/*!
 *
 * An instance of SinglyRequest to initialize the connection with.
 *
 * @available Available in Singly iOS SDK 1.2.0 and later.
 *
**/
@property (strong) SinglyRequest *request;

/*!
 *
 * Initializes and returns a new instance of SinglyConnection for the specified
 * request.
 *
 * @param request The SinglyRequest instance to use.
 *
 * @returns An instance of SinglyConnection.
 *
 * @available Available in Singly iOS SDK 1.2.0 and later.
 *
**/
+ (id)connectionWithRequest:(SinglyRequest *)request;

/*!
 *
 * Initializes and returns a new instance of SinglyConnection for the specified
 * request.
 *
 * @param request The SinglyRequest instance to use.
 *
 * @returns An instance of SinglyConnection.
 *
 * @available Available in Singly iOS SDK 1.2.0 and later.
 *
**/
- (id)initWithRequest:(SinglyRequest *)request;

/*!
 *
 * Performs the request synchronously.
 *
 * @param error Out parameter used if an error occurs while performing the
 *              request.
 *
 * @see performRequestWithCompletion:
 *
 * @available Available in Singly iOS SDK 1.2.0 and later.
 *
**/
- (id)performRequest:(NSError **)error;

/*!
 *
 * Performs the request asynchronously.
 *
 * @param completionHandler The block to call once the request has completed.
 *
 * @see performRequest:
 *
 * @available Available in Singly iOS SDK 1.2.0 and later.
 *
**/
- (void)performRequestWithCompletion:(SinglyConnectionRequestCompletionBlock)completionHandler;

@end
