#pragma once

#include <string>
#include <optional>
#include <memory>

namespace lsm {
    // Status codes for operations
    enum class Status {
        OK,                 // Operation succeeded
        NOT_FOUND,          // Key doesn't exist
        ERROR,              // Something went wrong
        CORRUPTION,         // Data is corrupted
        NOT_SUPPORTED,      // Feature not implemented
        INVALID_ARGUMENT    // Bad input provided
    };

    // Options for database operations
    struct WriteOptions {
        bool sync = false; // Should we wait for disk write?
    };

    struct ReadOptions {
        bool verify_checksums = false; // Should we verify data integrity?
    };

    // Abstract interface for key-value stores
    class KVStore {
        public:
            virtual ~KVStore() = default;

            // Basic operations
            virtual Status Put(const std::string& key, const std::string& value) = 0;
            virtual std::optional<std::string> Get(const std::string& key) = 0;
            virtual Status Delete(const std::string& key) = 0;

            // Utility methods
            virtual void PrintStats() const = 0;
    };
}