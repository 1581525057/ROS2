# Repository README Design

## Goal

Replace the topic-specific root README with a concise entry point for the entire ROS 2 learning repository, then publish all current local source changes to `origin/main`.

## Scope

- Document the four source workspaces: `CHAPT2/chapt2_ws`, `CHATP3/topic_ws`, `CHATP3/topic_practice_ws`, and `chapt4/chapt4_ws`.
- Provide a shared ROS 2 Humble build workflow and selected `ros2 run` entry points.
- State that workspace `build/`, `install/`, and `log/` directories are generated and excluded from version control.
- Do not change node behavior, package metadata, or generated artifacts.

## README Structure

1. Repository title, purpose, and environment badges.
2. A workspace table that maps each chapter to its packages and learning focus.
3. Prerequisites and the reusable build/setup sequence.
4. Short module-specific run commands for the most important demos.
5. Repository conventions and focused troubleshooting.

## Validation

- Confirm every documented workspace and package exists under a `src/` directory.
- Check Markdown headings and fenced code blocks render consistently.
- Run `git status` to confirm generated ROS 2 workspace output is not staged.
- Commit the documentation and current source changes, then push `main` to `origin`.
