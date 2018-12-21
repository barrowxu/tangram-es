#pragma once

#include "platform.h"

#include <unordered_map>

namespace Tangram {

class MockPlatform : public Platform {

public:

    void shutdown() override {}
    void requestRender() const override;
    std::vector<FontSourceHandle> systemFontFallbacksHandle() const override;
    UrlRequestId startUrlRequest(Url _url, UrlRequestHandle _request) override;
    void urlRequestCanceled(UrlRequestHandle _request) override;

    // Put content at a URL to be retrieved by startUrlRequest.
    void putMockUrlContents(Url url, std::string contents);
    void putMockUrlContents(Url url, std::vector<char> contents);


    // Get the contents of a local file (not mock URL contents).
    static std::vector<char> getBytesFromFile(const char* path);

private:

    std::unordered_map<Url, std::vector<char>> m_files;

};

} // namespace Tangram
