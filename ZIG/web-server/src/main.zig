// Async Webserver: TCP Listener + HTTP Protocol + parser

// two ways of using it
// 1. Library => creating a webserver with config
// 2. Executable => exe gets a config file in yaml

const std = @import("std");
const net = std.net;
const StreamServer = net.Server;
const Address = net.Address;

pub fn main() anyerror!void {
    // StreamServer.accept(s: *Server);
    std.debug.print("aorintn", .{});
}

