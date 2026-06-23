# ROS 2 Service HTML Tutorial Design

## Goal

Create a beginner-friendly single-page HTML tutorial from `service_communication_notes.md` that teaches how to create a ROS 2 `.srv` interface package, write Python service/client nodes, configure node parameters, observe parameter events, and remotely update parameters.

## Audience

The reader is new to ROS 2 and needs step-by-step guidance. The tutorial must explain what each command and code block does instead of assuming prior ROS 2 package knowledge.

## Format

- Output file: `service_communication_tutorial.html`
- One standalone HTML file with embedded CSS and JavaScript.
- Left navigation on desktop and top navigation on mobile.
- Copy buttons for all command and code blocks.
- Terminal-group labels for steps requiring multiple terminals.
- Beginner callouts for concepts, common mistakes, and expected output.

## Content Structure

1. Learning goals and prerequisite workspace path.
2. Service communication concept: Request and Response.
3. `.srv` interface definition and interface package creation.
4. Interface package `CMakeLists.txt` and `package.xml`.
5. Build and inspect the generated service type.
6. Python package creation.
7. Service server code and line-by-line explanation.
8. Service client code and line-by-line explanation.
9. Parameter callback, parameter event watcher, and remote parameter setter.
10. `setup.py` and `package.xml` configuration.
11. Build, run, parameter commands, and troubleshooting.

## UX Details

- Use restrained, readable colors with strong contrast.
- Use stable code-block dimensions and wrapping so long paths remain readable.
- Avoid external libraries so the file works directly in a browser.
- Keep the first screen focused on the tutorial, not a marketing hero.

## Verification

- Confirm the HTML file exists.
- Confirm it contains all required tutorial sections.
- Confirm JavaScript has no obvious syntax errors.
- Confirm generated file can be opened directly from disk.
