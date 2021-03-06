//
//  CDEEventMigrator.h
//  Test App iOS
//
//  Migrates events in and out of the event store.
//
//  Created by Drew McCormack on 5/10/13.
//  Copyright (c) 2013 The Mental Faculty B.V. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CDEDefines.h"

@class CDEEventStore;
@class CDEPersistentStoreEnsemble;

@interface CDEEventMigrator : NSObject

@property (readonly) CDEEventStore *eventStore;
@property (readwrite, nonatomic) NSString *storeTypeForNewFiles;
@property (nonatomic, readwrite, weak) CDEPersistentStoreEnsemble *ensemble;

- (instancetype)initWithEventStore:(CDEEventStore *)newStore;

- (void)migrateLocalEventWithRevision:(CDERevisionNumber)revision toFile:(NSString *)path completion:(CDECompletionBlock)completion;
- (void)migrateLocalEventsSinceRevision:(CDERevisionNumber)revision toFile:(NSString *)path completion:(CDECompletionBlock)completion;
- (void)migrateEventsInFromFiles:(NSArray *)paths completion:(CDECompletionBlock)completion;

@end
